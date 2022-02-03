/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:58:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:20:09 by pleveque         ###   ########.fr       */
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
		if (last > stack->v[i])
			return (0);
		last = stack->v[i];
	}
	return (1);
}
