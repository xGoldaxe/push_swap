/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:28:10 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 18:01:38 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_stack_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->v[i])
		++i;
	return (i);
}

int	ft_stack_include(int value, t_stack *ref)
{
	int	i;

	i = 0;
	while (i < ref->size)
	{
		if (ref->v[i] == value)
			return (1);
		++i;
	}
	return (0);
}

int	push_out_from_stack(t_stack *stack_a,
t_stack *stack_b, t_stack *stack_lis)
{
	int	i;

	i = 0;
	while (stack_a->size > stack_lis->size)
	{
		if (ft_stack_include(stack_a->v[stack_a->size - 1], stack_lis))
		{
			operation(RA, stack_a, stack_b);
			if (i < stack_lis->size - 1)
				++i;
		}
		else
			operation(PB, stack_a, stack_b);
	}
	return (0);
}
