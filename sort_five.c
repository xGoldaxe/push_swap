/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/06 17:56:33 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the right index in a sorted stack */

int	stack_find_insert_index(t_stack *stack, int value)
{
	int	i;
	int	tmp;

	tmp = stack_higher(stack);
	if (value > stack->v[tmp])
		return (tmp);
	tmp = stack_lower(stack);
	if (value < stack->v[tmp])
		return (tmp);
	i = stack->size;
	while (--i)
	{
		if (value > stack->v[i] && value < stack->v[i - 1])
			return (i);
	}
	if (value > stack->v[0] && value < stack->v[stack->size - 1])
		return (0);
	return (-1);
}

int	stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	insert_index;

	insert_index = stack_find_insert_index(stack_a,
				stack_b->v[stack_b->size - 1]);
	if (insert_index < stack_a->size / 2)
	{
		// printf("sort top, %d\n", stack_b->v[stack_b->size - 1]);
		i = stack_a->size - insert_index;
		while (--i)
			operation(RA, stack_a, stack_b);
		operation(PA, stack_a, stack_b);
		if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
			operation(SA, stack_a, stack_b);
	}
	else
	{
		i = insert_index + 1;
		while (--i)
			operation(RRA, stack_a, stack_b);
		operation(PA, stack_a, stack_b);
	}
	return (0);
}

int	stack_merge(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
		stack_insert(stack_a, stack_b);
	return (0);
}

int	stack_bubble(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_higher(stack_a) > stack_a->size / 2)
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
