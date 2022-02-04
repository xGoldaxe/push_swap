/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:17:39 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/04 12:52:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int	higher;
	int	lower;

	higher = stack_higher(stack_a);
	lower = stack_lower(stack_a);
	if (higher == 0 && lower == 1)
		operation(SA, stack_a, stack_b);
	if (higher == 2 && lower == 0)
	{
		operation(SA, stack_a, stack_b);
		operation(RRA, stack_a, stack_b);
	}
	if (higher == 2 && lower == 1)
		operation(RA, stack_a, stack_b);
	if (higher == 1 && lower == 2)
	{
		operation(SA, stack_a, stack_b);
		operation(RA, stack_a, stack_b);
	}
	if (higher == 1 && lower == 0)
		operation(RRA, stack_a, stack_b);
	return (0);
}
