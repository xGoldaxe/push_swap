/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_regular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:28:10 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/08 18:39:18 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_stack_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->v[i])
		++i;
	return (i);
}

int	cpy_stack(t_stack *src, t_stack *dst)
{
	int	i;

	dst = malloc(sizeof(int) * src->size);
	if (!dst)
		return (-1);
	i = 0;
	while (i < src->size)
	{
		dst->v[i] = src->v[i];
		++i;
	}
	return (0);
}

int	ft_stack_include(int value, t_stack *ref)
{
	int	i;

	i = 0;
	while (i < ref->size)
	{
		if (ref->v[i] == value)
			return (1);
		++i;
	}
	return (0);
}

int	push_out_from_stack(t_stack *stack_a,
t_stack *stack_b, t_stack *stack_lis)
{
	while (verify_sorted_stack(stack_a) == 0)
	{
		if (ft_stack_include(stack_a->v[stack_a->size - 1], stack_lis))
			operation(RA, stack_a, stack_b);
		operation(PB, stack_a, stack_b);
	}
	return (0);
}

int	get_number_operation(t_stack *stack_a, int value)
{
	int	i;
	int	insert_index;
	int	operations;

	operations = 0;
	insert_index = stack_find_insert_index(stack_a,
				value);
	//calculate the number of RRA and RRB needed, also SA and SB
	//number of operations = |RRA - RRB| + |SA - SB|
	if (insert_index >= stack_a->size / 2)
	{
		i = stack_a->size - insert_index - 1;
		insert_index = i;
		while (i > 0)
		{
			operations++;
			--i;
		}
		operations++;
		// if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
		// 	operation(SA, stack_a, stack_b);
	}
	else
	{
		i = insert_index;
		while (i > 0)
		{
			operations++;
			--i;
		}
		operations++;
		operations++;
		// if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
		// {
		// 	operation(SA, stack_a, stack_b);
		// }
	}
	return (operations);
}

int	stack_insert_operations(t_stack *stack_a, t_stack *stack_b)
{
	int	number_of_operations;
	int	best_number_of_operations;
	int	best_index;
	int	i;

	best_number_of_operations = -1;
	i = stack_b->size;
	while (--i >= 0)
	{
		number_of_operations = get_number_operation(stack_a, stack_b->v[i]);
		if (number_of_operations < best_number_of_operations || best_number_of_operations == -1)
		{
			best_number_of_operations = number_of_operations;
			best_index = i;
		}
	}
	return (best_index);
}

int	stack_insert_index(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	stack_insert(stack_a, stack_b);
	if (index < stack_b->size / 2)
	{
		i = 0;
		while (i < index)
		{
			operation(RB, stack_a, stack_b);
			++i;
		}
	}
	else
	{
		i = stack_b->size - index + 1;
		while (--i)
			operation(RRB, stack_a, stack_b);
	}
	stack_insert(stack_a, stack_b);
	return (0);
}

int sort_regular(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *stack_lis;
	(void)stack_b;

	stack_lis = stack_to_lis(stack_a);
	if (!stack_lis)
		exit(0);
	push_out_from_stack(stack_a, stack_b, stack_lis);
	while (stack_b->size)
		stack_insert_index(stack_a, stack_b, stack_insert_operations(stack_a, stack_b));
	stack_bubble(stack_a, stack_b);
	free(stack_lis);
    return (0);
}
