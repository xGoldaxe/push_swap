/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:46:51 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 19:10:25 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_cpy(t_stack *src, t_stack *dst, int size)
{
	free(dst->v);
	stack_cpy(src, dst, size);
}

int	lis_error(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	free(a);
	free(b);
	clean_exit(stack_a, stack_b);
	return (0);
}

t_stack	*get_lis(t_stack *stack_a, t_stack *stack_b, int iter, int print_op)
{
	t_stack	*stack_lis;
	t_stack	o_a;
	t_stack	o_b;
	int		size;
	int		i;

	size = stack_a->size + stack_b->size;
	stack_cpy(stack_a, &o_a, size);
	stack_cpy(stack_b, &o_b, size);
	if (!o_a.v || !o_b.v)
		lis_error(stack_a, stack_b, o_a.v, o_b.v);
	i = -1;
	while (++i < iter)
		operation(RA, stack_a, stack_b);
	operation(-1, 0, 0);
	if (print_op)
		operation(-4, 0, 0);
	stack_lis = stack_to_lis(stack_a);
	free_stack_cpy(&o_a, stack_a, size);
	if (!stack_a->v)
	{
		if (stack_lis)
			free_stack(stack_lis);
	}
	return (free(o_a.v), free(o_b.v), stack_lis);
}

int	sort_with_lis(t_stack *stack_a, t_stack *stack_b, int iter, int print_op)
{
	t_stack	o_a;
	t_stack	o_b;
	int		size;
	t_stack	*stack_lis;

	size = stack_a->size + stack_b->size;
	stack_cpy(stack_a, &o_a, size);
	stack_cpy(stack_b, &o_b, size);
	stack_lis = get_lis(stack_a, stack_b, iter, print_op);
	if (!stack_lis)
		lis_error(stack_a, stack_b, o_a.v, o_b.v);
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
