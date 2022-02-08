/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/08 18:41:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the right index in a sorted stack */

int	stack_find_insert_index(t_stack *stack, int value)
{
	int	i;
	int	tmp;

	tmp = stack_higher(stack);
	if (value > stack->v[tmp])
	{
		// printf("CAS 1 LE TOP B C LE PLUS GRAND %d\n", value);
		return (tmp);
	}
	tmp = stack_lower(stack);
	if (value < stack->v[tmp])
	{
		// printf("CAS 1 LE TOP B C LE PLUS PETIT %d\n", value);
		return (tmp);
	}
	// printf("On doit trouver la bonne pos\n");
	// print_stack(stack);
	i = stack->size;
	while (--i)
	{
		if (value > stack->v[i] && value < stack->v[i - 1])
			return (i);
	}
	if (value > stack->v[0] && value < stack->v[stack->size - 1])
		return (0);
	return (-1);
}

int	stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	insert_index;

	// printf("-----start----\n");
	insert_index = stack_find_insert_index(stack_a,
				stack_b->v[stack_b->size - 1]);
	if (insert_index >= stack_a->size / 2)
	{
		// printf("insert ra top, %d, index %d\n", stack_b->v[stack_b->size - 1], insert_index);
		i = stack_a->size - insert_index - 1;
		insert_index = i;
		while (i > 0)
		{
			operation(RA, stack_a, stack_b);
			--i;
		}
		operation(PA, stack_a, stack_b);
		if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
			operation(SA, stack_a, stack_b);
	}
	else
	{
		// printf("insert rra bottom, %d, index %d\n", stack_b->v[stack_b->size - 1], insert_index);
		i = insert_index;
		while (i > 0)
		{
			operation(RRA, stack_a, stack_b);
			--i;
		}
		operation(RRA, stack_a, stack_b);
		operation(PA, stack_a, stack_b);
		if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
			operation(SA, stack_a, stack_b);
	}
	// printf("-----end----\n");
	// print_stack(stack_a);
	return (0);
}

int	stack_merge(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
		stack_insert(stack_a, stack_b);
	return (0);
}

int	get_anomaly(t_stack *stack_a)
{
	int	res;

	res = 0;
	while (res < stack_a->size - 1)
	{
		if (stack_a->v[res] < stack_a->v[res + 1])
			return (res);
		++res;
	}
	return (-1);
}

int	stack_bubble(t_stack *stack_a, t_stack *stack_b)
{
	int	res;

	res = get_anomaly(stack_a);
	if (res == -1)
		return (0);
	if (res < stack_a->size / 2)
	{
		while (stack_lower(stack_a) != stack_a->size - 1)
			operation(RRA, stack_a, stack_b);
	}
	else
	{
		while (stack_lower(stack_a) != stack_a->size - 1)
			operation(RA, stack_a, stack_b);
	}
	// print_stack(stack_a);
	return (0);
}

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5)
		operation(PB, stack_a, stack_b);
	operation(PB, stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	// print_stack(stack_a);
	stack_merge(stack_a, stack_b);
	stack_bubble(stack_a, stack_b);
	return (0);
}
