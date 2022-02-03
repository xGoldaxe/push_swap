/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:38:04 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:06:27 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swapper.h"

static int	rotate_stack(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	if (stack->size >= 1)
	{
		tmp = stack->v[0];
		while (++i < stack->size - 1)
			stack->v[i] = stack->v[i + 1];
		stack->v[i] = tmp;
		return (0);
	}
	return (-1);
}

/* shift up all elements of stack A by 1. The first element becomes
the last one */

int	rotate_ra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	return (rotate_stack(stack_a));
}

/* shift up all elements of stack B by 1. The first element becomes
the last one */

int	rotate_rb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	return (rotate_stack(stack_b));
}

int	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	return (0);
}
