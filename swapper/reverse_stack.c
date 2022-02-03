/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:49:58 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:06:30 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swapper.h"

static int	reverse_stack(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->size - 1;
	if (stack->size >= 1)
	{
		tmp = stack->v[i];
		while (--i >= 0)
			stack->v[i + 1] = stack->v[i];
		stack->v[0] = tmp;
		return (0);
	}
	return (-1);
}

/* shift down all elements of stack A by 1. The last element
becomes the first one */

int	reverse_rra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	return (reverse_stack(stack_a));
}

/* shift down all elements of stack B by 1. The last element
becomes the first one */

int	reverse_rrb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	return (reverse_stack(stack_b));
}

int	reverse_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_stack(stack_a);
	reverse_stack(stack_b);
	return (0);
}
