/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:20:33 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:20:46 by pleveque         ###   ########.fr       */
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
