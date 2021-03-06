/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_regular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 18:47:47 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the right index in a sorted stack */

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5)
		operation(PB, stack_a, stack_b);
	operation(PB, stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	return (0);
}

int	sort_regular_iter(t_stack *stack_a, t_stack *stack_b, t_stack *stack_lis)
{
	(void)stack_b;
	push_out_from_stack(stack_a, stack_b, stack_lis);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	return (0);
}

int	sort_regular(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		best_operations;
	int		iter;
	int		iter_best;

	size = stack_a->size + stack_b->size;
	iter = 0;
	best_operations = -1;
	operation(-3, 0, 0);
	while (iter < size)
	{
		sort_with_lis(stack_a, stack_b, iter, 0);
		if (operation(-2, 0, 0) < best_operations || best_operations == -1)
		{
			iter_best = iter;
			best_operations = operation(-2, 0, 0);
		}
		operation(-1, 0, 0);
		if (size > 10)
			iter += size / 10;
		else
			++iter;
	}
	sort_with_lis(stack_a, stack_b, iter_best, 1);
	return (0);
}
