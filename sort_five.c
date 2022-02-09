/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/09 18:09:59 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the right index in a sorted stack */

int	stack_find_insert_index(t_stack *stack, int value)
{
	int	i;
	int	tmp;
	int	best;

	best = -1;
	tmp = stack_higher(stack);
	if (value > stack->v[tmp])
	{
		// printf("CAS 1 LE TOP B C LE PLUS GRAND %d\n", value);
		return (tmp);
	}
	tmp = stack_lower(stack);
	if (value < stack->v[tmp])
	{
		// printf("CAS 1 LE TOP B C LE PLUS PETIT %d\n", value);
		return (tmp);
	}
	// printf("On doit trouver la bonne pos\n");
	// print_stack(stack);
	i = stack->size - 1;
	while (i > 0)
	{
		if (value > stack->v[i] && value < stack->v[i - 1])
		{
			best = i;
			i = 0;
		}
		--i;
	}
	//si c4est le premier element
	if (value > stack->v[0] && value < stack->v[stack->size - 1])
		best = 0;
	return (best);
}

t_operations	*get_number_operation(t_stack *stack_a, int value, t_operations *operations)
{
	int	insert_index;

	insert_index = stack_find_insert_index(stack_a,
				value);
	//calculate the number of RRA and RRB needed, also SA and SB
	//number of operations = |RRA - RRB| + |RA - RRA| + sa + sb
	// RRR = |RRA - RRB|
	if (insert_index >= stack_a->size / 2)
	{
		operations->ra = stack_a->size - insert_index - 1;
		if (stack_a->v[stack_a->size - 1 - operations->ra] < value)
			operations->sa = 1;
		operations->pa = 1;
	}
	else
	{
		operations->rra = insert_index + 1;
		operations->pa = 1;
		if (stack_a->v[insert_index] < value)
			operations->sa = 1;
	}
	return (operations);
}

int	stack_insert_real(t_stack *stack_a, t_stack *stack_b, t_operations *operations)
{

	// printf("-----start----\n");
	while (operations->rr > 0 )
	{
		operation(RR, stack_a, stack_b);
		operations->rr--;
	}
	while (operations->ra-- > 0)
		operation(RA, stack_a, stack_b);
	while (operations->rb-- > 0)
		operation(RB, stack_a, stack_b);
	while (operations->rrr > 0)
	{
		operation(RRR, stack_a, stack_b);
		operations->rrr--;
	}
	while (operations->rra-- > 0)
		operation(RRA, stack_a, stack_b);
	while (operations->rrb-- > 0)
		operation(RRB, stack_a, stack_b);
	operation(PA, stack_a, stack_b);
	if (operations->sa)
		operation(SA, stack_a, stack_b);
	if (operations->sb)
		operation(SB, stack_a, stack_b);
	// printf("-----end------\n");
	return (0);
}

t_operations	*operations_default(t_operations *operations)
{
	operations->ra = 0;
	operations->rb = 0;
	operations->rra = 0;
	operations->rrb = 0;
	operations->sa = 0;
	operations->sb = 0;
	operations->rr = 0;
	operations->rrr = 0;
	return (operations);
}

t_operations	*operations_cpy(t_operations *src, t_operations *dst)
{
	dst->ra = src->ra;
	dst->rb = src->rb;
	dst->rra = src->rra;
	dst->rrb = src->rrb;
	dst->sa = src->sa;
	dst->sb = src->sb;
	dst->rr = src->rr;
	dst->rrr = src->rrr;
	return (dst);
}

t_operations	*get_pushback_operation(t_stack *stack, int index, t_operations *operations)
{
	if (index >= stack->size / 2)
		operations->rb = stack->size - 1 - index;
	else
		operations->rrb = index + 1;
	return (operations);
}

int stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	t_operations	operations;
	t_operations	operations_insert;
	int				i;
	int				nbr_operations;
	int				best_nbr_operations;
	//for each b
	if (stack_b->size <= 0)
		return (-1);
	i = 0;
	best_nbr_operations = -1;
	// printf("STACK INSERT --->\n");
	//print_stack(stack_a);
	//print_stack(stack_b);
	while (i < stack_b->size)
	{
		operations_default(&operations);
		get_number_operation(stack_a, stack_b->v[i], &operations);
		get_pushback_operation(stack_b, i, &operations);
		if (operations.ra >= operations.rb)
		{
			operations.ra = operations.ra - operations.rb;
			operations.rr = operations.rb;
			operations.rb = 0;
		}
		else
		{
			operations.rb -= operations.ra;
			operations.rr = operations.ra;
			operations.ra = 0;
		}
		if (operations.rra >= operations.rrb)
		{
			operations.rra -= operations.rrb;
			operations.rrr = operations.rrb;
			operations.rrb = 0;
		}
		else
		{
			operations.rrb -= operations.rra;
			operations.rrr = operations.rra;
			operations.rra = 0;
		}
		nbr_operations = operations.ra + operations.rb + operations.rra + operations.rrb
			+ operations.rr + operations.rrr + operations.sa;
		//printf("Pour le TOP : %d ON A %d ope !\n", stack_b->v[i], nbr_operations);
		if (nbr_operations < best_nbr_operations || best_nbr_operations == -1)
		{
			// printf("best index so far %d\n", i);
			best_nbr_operations = nbr_operations;
			operations_cpy(&operations, &operations_insert);
		}
		++i;
	}
	stack_insert_real(stack_a, stack_b, &operations_insert);
	// print_stack(stack_a);
	// print_stack(stack_b);
	// printf("<----- STACK INSERT\n");
	return (0);
}

int	stack_merge(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
		stack_insert(stack_a, stack_b);
	return (0);
}

int	get_anomaly(t_stack *stack_a)
{
	int	res;

	res = 0;
	while (res < stack_a->size - 1)
	{
		if (stack_a->v[res] < stack_a->v[res + 1])
			return (res);
		++res;
	}
	return (-1);
}

int	stack_bubble(t_stack *stack_a, t_stack *stack_b)
{
	int	res;

	res = get_anomaly(stack_a);
	if (res == -1)
		return (0);
	if (res < stack_a->size / 2)
	{
		while (stack_lower(stack_a) != stack_a->size - 1)
			operation(RRA, stack_a, stack_b);
	}
	else
	{
		while (stack_lower(stack_a) != stack_a->size - 1)
			operation(RA, stack_a, stack_b);
	}
	// print_stack(stack_a);
	return (0);
}

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5)
		operation(PB, stack_a, stack_b);
	operation(PB, stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	// print_stack(stack_a);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	return (0);
}

int	sort_regular_iter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *stack_lis;
	(void)stack_b;

	stack_lis = stack_to_lis(stack_a);
	if (!stack_lis)
		exit(0);
	push_out_from_stack(stack_a, stack_b, stack_lis);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	free(stack_lis);
    return (0);
}

t_stack	*stack_cpy(t_stack *src, t_stack *dst, int size)
{
	int	i;

	dst->v = malloc(sizeof(int) * size);
	dst->size = src->size;
	i = 0;
	while (i < src->size)
	{
		dst->v[i] = src->v[i];
		++i;
	}
	return (dst);
}

int sort_regular(t_stack *stack_a, t_stack *stack_b)
{
	t_stack older_stack_a;
	t_stack older_stack_b;
	int		size;
	int		best_operations;
	int		operations;
	int		i;

	size = stack_a->size + stack_b->size;
	stack_cpy(stack_a, &older_stack_a, size);
	stack_cpy(stack_b, &older_stack_b, size);
	best_operations = -1;
	i = 0;
	while (i < size)
	{
		//get a lis from i
		sort_regular_iter(stack_a, stack_b);
		operations = operation(-2, NULL, NULL);
		if (operations < best_operations || best_operations == -1)
			best_operations = operations;
		operation(-1, NULL, NULL);
		free(stack_a->v);
		free(stack_b->v);
		stack_cpy(&older_stack_a, stack_a, size);
		stack_cpy(&older_stack_b, stack_b, size);
		i += 50;
	}
	free(older_stack_a.v);
	free(older_stack_b.v);
	printf("BEST OPERATIONS %d\n", best_operations);
	return (0);
}
