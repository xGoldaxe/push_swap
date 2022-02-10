/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:58:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:58:30 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_sorted_stack(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->size <= 0)
		return (-1);
	i = 0;
	last = stack->v[0];
	while (++i < stack->size)
	{
		if (last < stack->v[i])
			return (0);
		last = stack->v[i];
	}
	return (1);
}

int	stack_test_value(t_stack *stack, int (*f_test)(int value_a, int value_b))
{
	int	i;
	int	best_value;
	int	index;

	if (stack->size)
	{
		best_value = stack->v[0];
		index = 0;
		i = stack->size;
		while (--i)
		{
			if (f_test(stack->v[i], best_value))
			{
				best_value = stack->v[i];
				index = i;
			}
		}
		return (index);
	}
	return (-1);
}

int	stack_lower(t_stack *stack)
{
	return (stack_test_value(stack, is_lower));
}

int	stack_higher(t_stack *stack)
{
	return (stack_test_value(stack, is_higher));
}

t_stack	*stack_cpy(t_stack *src, t_stack *dst, int size)
{
	int	i;

	dst->v = malloc(sizeof(int) * size);
	if (!dst->v)
		return (NULL);
	dst->size = src->size;
	i = 0;
	while (i < src->size)
	{
		dst->v[i] = src->v[i];
		++i;
	}
	return (dst);
}
