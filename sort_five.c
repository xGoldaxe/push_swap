/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:59:25 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/04 18:07:47 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the rigt index in a sorted stack */

int	stack_find_insert_index(t_stack *stack, int value)
{
	int	i;
	int	anomaly;

	anomaly =- 1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->v[i] < stack->v[i + 1])
			anomaly = i + 1;
		++i;
	}
	i = 0;
	while (i < stack->size)
	{
		if (value > stack->v[i] && i == 0)
		{
			if (anomaly == -1 || value < stack->v[stack->size - 1])
				return (i);
		}
		else if (value > stack->v[i] && value < stack->v[i - 1])
			return (i);
		else if (stack->v[i] < stack->v[i + 1] && value > stack->v[i + 1])
			return (i + 1);
		++i;
	}
	return (-1);
}

int	stack_insert(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	insert_index;

	insert_index = stack_find_insert_index(stack_a,
				stack_b->v[stack_b->size - 1]);
	printf("index is %d ||", insert_index);
	return 0;
	if (insert_index > stack_a->size / 2)
	{
		printf("add at top\n");
		i = stack_a->size - insert_index;
		while (--i)
			operation(RA, stack_a, stack_b);
		operation(PA, stack_a, stack_b);
		if (stack_a->v[stack_a->size - 1] > stack_a->v[stack_a->size - 2])
			operation(SA, stack_a, stack_b);
	}
	else
	{
		printf("add at bottom\n");
		i = insert_index + 1;
		while (--i)
			operation(RRA, stack_a, stack_b);
		operation(PA, stack_a, stack_b);
	}
	return (0);
}

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	operation(PB, stack_a, stack_b);
	operation(PB, stack_a, stack_b);
	sort_stack(stack_a, stack_b);

	printf("index is %d ||\n", stack_find_insert_index(stack_a,
				3));
	return 0;
	while (stack_b->size)
	{
		stack_insert(stack_a, stack_b);
		printf("=====top=====\n");
		print_stack(stack_a);
		printf("=============\n");
	}
	// print_stack(stack_a);
	// printf("=============\n");
	// while (!verify_sorted_stack(stack_a))
	// 	operation(RA, stack_a, stack_b);
	return (0);
}
