/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:24:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:06:33 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swapper.h"

static int	push_stack(t_stack *stack_1, t_stack *stack_2)
{
	if (!stack_2->size)
		return (-1);
	stack_1->v[stack_1->size] = stack_2->v[stack_2->size - 1];
	stack_1->size += 1;
	stack_2->size -= 1;
	return (0);
}

/* take the top element of B and put in to the top of A */

int	push_pa(t_stack *stack_a, t_stack *stack_b)
{
	return (push_stack(stack_a, stack_b));
}

/* take the top element of A and put in to the top of B */

int	push_pb(t_stack *stack_a, t_stack *stack_b)
{
	return (push_stack(stack_b, stack_a));
}
