/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:20:05 by pleveque         ###   ########.fr       */
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
		return (tmp);
	tmp = stack_lower(stack);
	if (value < stack->v[tmp])
	{
		// if (tmp == 0)
		// 	return (0);
		return (tmp + 1);
	}
	i = stack->size - 1;
	// if (value < stack->v[stack->size - 1] && value > stack->v[0])
	// 	return (stack->size - 1);
	while (i > 0)
	{
		if (value > stack->v[i] && value < stack->v[i - 1])
		{
			best = i;
			i = 0;
		}
		--i;
	}
	if (value > stack->v[0] && value < stack->v[stack->size - 1])
		best = 0;
	return (best);
}

t_operations	*get_number_operation(t_stack *stack_a, int value, t_operations *operations)
{
	int	insert_index;

	insert_index = stack_find_insert_index(stack_a,
				value);
	if (insert_index >= stack_a->size / 2)
	{
		operations->ra = stack_a->size - insert_index;
		// if (stack_a->v[stack_a->size - 1 - operations->ra] < value)
		// 	operations->sa = 1;
		operations->pa = 1;
	}
	else
	{
		operations->rra = insert_index;
		operations->pa = 1;
	}
	return (operations);
}

int	stack_insert_real(t_stack *stack_a, t_stack *stack_b, t_operations *operations)
{

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
	return (0);
}

int	stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	t_operations	operations;
	t_operations	operations_insert;
	int				i;
	int				nbr_operations;
	int				best_nbr_operations;

	if (stack_b->size <= 0)
		return (-1);
	i = 0;
	best_nbr_operations = -1;
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
		nbr_operations = operations.ra + operations.rb
			+ operations.rra + operations.rrb
			+ operations.rr + operations.rrr + operations.sa;
		if (nbr_operations < best_nbr_operations || best_nbr_operations == -1)
		{
			best_nbr_operations = nbr_operations;
			operations_cpy(&operations, &operations_insert);
		}
		++i;
	}
	stack_insert_real(stack_a, stack_b, &operations_insert);
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
	return (0);
}

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5)
		operation(PB, stack_a, stack_b);
	operation(PB, stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	return (0);
}

int	sort_regular_iter(t_stack *stack_a, t_stack *stack_b, t_stack *stack_lis)
{
	(void)stack_b;

	push_out_from_stack(stack_a, stack_b, stack_lis);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
    return (0);
}

int	sort_with_lis(t_stack *stack_a, t_stack *stack_b, int iter, int print_op)
{
	t_stack older_stack_a;
	t_stack older_stack_b;
	int		i;
	int		size;
	t_stack	*stack_lis;

	size = stack_a->size + stack_b->size;
	stack_cpy(stack_a, &older_stack_a, size);
	stack_cpy(stack_b, &older_stack_b, size);
	i = 0;
	while (i < iter)
	{
		operation(RA, stack_a, stack_b);
		++i;
	}
	operation(-1, 0, 0);
	if (print_op)
		operation(-4, 0, 0);
	stack_lis = stack_to_lis(stack_a);
	free(stack_a->v);
	stack_cpy(&older_stack_a, stack_a, size);
	sort_regular_iter(stack_a, stack_b, stack_lis);
	if (print_op == 0)
	{
		free(stack_a->v);
		free(stack_b->v);
		stack_cpy(&older_stack_a, stack_a, size);
		stack_cpy(&older_stack_b, stack_b, size);
	}
	free(older_stack_a.v);
	free(older_stack_b.v);
	free_stack(stack_lis);
	operation(-3, 0, 0);
	return (0);
}

int sort_regular(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		best_operations;
	int		iter;
	int		iter_best;

	size = stack_a->size + stack_b->size;
	iter = 0;
	best_operations = -1;
	operation(-3, 0, 0);
	while (iter < size)
	{
		sort_with_lis(stack_a, stack_b, iter, 0);
		if (operation(-2, 0, 0) < best_operations || best_operations == -1)
		{
			iter_best = iter;
			best_operations = operation(-2, 0, 0);
		}
		operation(-1, 0, 0);
		if (size > 10)
			iter += size / 10;
		else
			++iter;
	}
	sort_with_lis(stack_a, stack_b, iter_best, 1);
	return (0);
}
