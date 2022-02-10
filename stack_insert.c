/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:30:10 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (tmp + 1);
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
	if (value > stack->v[0] && value < stack->v[stack->size - 1])
		best = 0;
	return (best);
}

t_operations	*get_number_operation(t_stack *stack_a, int value,
t_operations *operations)
{
	int	insert_index;

	insert_index = stack_find_insert_index(stack_a,
			value);
	if (insert_index >= stack_a->size / 2)
	{
		operations->ra = stack_a->size - insert_index;
		operations->pa = 1;
	}
	else
	{
		operations->rra = insert_index;
		operations->pa = 1;
	}
	return (operations);
}

int	stack_insert_real(t_stack *stack_a, t_stack *stack_b,
t_operations *operations)
{
	while (operations->rr > 0)
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

t_operations	*get_merge_reverse(t_operations *operations)
{
	if (operations->ra >= operations->rb)
	{
		operations->ra = operations->ra - operations->rb;
		operations->rr = operations->rb;
		operations->rb = 0;
	}
	else
	{
		operations->rb -= operations->ra;
		operations->rr = operations->ra;
		operations->ra = 0;
	}
	if (operations->rra >= operations->rrb)
	{
		operations->rra -= operations->rrb;
		operations->rrr = operations->rrb;
		operations->rrb = 0;
	}
	else
	{
		operations->rrb -= operations->rra;
		operations->rrr = operations->rra;
		operations->rra = 0;
	}
	return (operations);
}

int	stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	t_operations	o;
	t_operations	operations_insert;
	int				i;
	int				nbr_operations;
	int				best_nbr_operations;

	if (stack_b->size <= 0)
		return (-1);
	i = -1;
	best_nbr_operations = -1;
	while (++i < stack_b->size)
	{
		operations_default(&o);
		get_number_operation(stack_a, stack_b->v[i], &o);
		get_pushback_operation(stack_b, i, &o);
		get_merge_reverse(&o);
		nbr_operations = o.ra + o.rb + o.rra + o.rrb + o.rr + o.rrr + o.sa;
		if (nbr_operations < best_nbr_operations || best_nbr_operations == -1)
		{
			best_nbr_operations = nbr_operations;
			operations_cpy(&o, &operations_insert);
		}
	}
	stack_insert_real(stack_a, stack_b, &operations_insert);
	return (0);
}
