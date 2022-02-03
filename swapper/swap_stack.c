/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:37:04 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:06:35 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swapper.h"

static int	swap_stack(t_stack *stack)
{
	int	tmp;
	int	size;

	size = stack->size;
	if (size >= 2)
	{
		tmp = stack->v[size - 1];
		stack->v[size - 1] = stack->v[size - 2];
		stack->v[size - 2] = tmp;
	}
	return (0);
}

/* swap the two top elements of A */

int	swap_sa(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	return (swap_stack(stack_a));
}

/* swap the two top elements of B */

int	swap_sb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	return (swap_stack(stack_b));
}

/* swap the two top elements of A and B */

int	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	return (0);
}
