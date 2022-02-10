/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:20:33 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:42:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack->v)
		free(stack->v);
	free(stack);
	return (NULL);
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

int	stack_merge(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
		stack_insert(stack_a, stack_b);
	return (0);
}
