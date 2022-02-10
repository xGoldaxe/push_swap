/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_regular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 18:04:11 by pleveque         ###   ########.fr       */
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

void	free_stack_cpy(t_stack *src, t_stack *dst, int size)
{
	free(dst->v);
	stack_cpy(src, dst, size);
}

//to norm
int	sort_with_lis(t_stack *stack_a, t_stack *stack_b, int iter, int print_op)
{
	t_stack	o_a;
	t_stack	o_b;
	int		i;
	int		size;
	t_stack	*stack_lis;

	size = stack_a->size + stack_b->size;
	stack_cpy(stack_a, &o_a, size);
	stack_cpy(stack_b, &o_b, size);
	if (!o_a.v || !o_b.v)
	{
		free(o_a.v);
		free(o_b.v);
		clean_exit(stack_a, stack_b);
	}
	i = -1;
	while (++i < iter)
		operation(RA, stack_a, stack_b);
	operation(-1, 0, 0);
	if (print_op)
		operation(-4, 0, 0);
	stack_lis = stack_to_lis(stack_a);
	free_stack_cpy(&o_a, stack_a, size);
	if (!stack_a->v || !stack_lis)
	{
		free_stack(stack_lis);
		free(o_b.v);
		free(o_a.v);
		clean_exit(stack_a, stack_b);
	}
	sort_regular_iter(stack_a, stack_b, stack_lis);
	free_stack(stack_lis);
	free_stack_cpy(&o_a, stack_a, size);
	free_stack_cpy(&o_b, stack_b, size);
	free(o_b.v);
	free(o_a.v);
	if (!stack_a->v || !stack_b->v)
		clean_exit(stack_a, stack_b);
	operation(-3, 0, 0);
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
