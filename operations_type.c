/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:27:21 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 14:38:53 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	*operations_default(t_operations *operations)
{
	operations->ra = 0;
	operations->rb = 0;
	operations->rra = 0;
	operations->rrb = 0;
	operations->sa = 0;
	operations->sb = 0;
	operations->rr = 0;
	operations->rrr = 0;
	return (operations);
}

t_operations	*operations_cpy(t_operations *src, t_operations *dst)
{
	dst->ra = src->ra;
	dst->rb = src->rb;
	dst->rra = src->rra;
	dst->rrb = src->rrb;
	dst->sa = src->sa;
	dst->sb = src->sb;
	dst->rr = src->rr;
	dst->rrr = src->rrr;
	return (dst);
}

t_operations	*get_pushback_operation(t_stack *stack, int index,
t_operations *operations)
{
	if (index >= stack->size / 2)
		operations->rb = stack->size - 1 - index;
	else
		operations->rrb = index + 1;
	return (operations);
}
