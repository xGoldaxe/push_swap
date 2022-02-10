/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:05 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 19:12:05 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (verify_sorted_stack(stack_a))
		return (1);
	else if (stack_a->size == 2)
	{
		if (stack_a->v[0] < stack_a->v[1])
			operation(SA, stack_a, stack_b);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort_regular(stack_a, stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.size = argc - 1;
	stack_a.v = store_stack(&argv[1], stack_a.size);
	stack_b.v = malloc(sizeof(int) * stack_a.size);
	stack_b.size = 0;
	if (!stack_a.v || !stack_b.v)
		clean_exit(&stack_a, &stack_b);
	sort_stack(&stack_a, &stack_b);
	clean_exit(&stack_a, &stack_b);
	return (0);
}

int	clean_exit(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->v);
	free(stack_b->v);
	exit(0);
	return (0);
}
