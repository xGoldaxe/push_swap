/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:05 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/03 20:33:32 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	operation(RA, stack_a, stack_b);
	//here we select the right algorithm for our A size
	return (0);
}

void	print_stack(t_stack	*stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->v[i]);
		++i;
	}
	printf("the stack sort is: %d\n", verify_sorted_stack(stack));
}

int	*store_stack(char **stack_str, int stack_size)
{
	int	i;
	int	*stack;

	stack = malloc(sizeof(int) * stack_size);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < stack_size)
	{
		stack[i] = ft_atoi(stack_str[i]);
		++i;
	}
	return (stack);
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
	{
		free(stack_a.v);
		free(stack_b.v);
		return (-1);
	}
	sort_stack(&stack_a, &stack_b);
	print_stack(&stack_a);
	free(stack_a.v);
	free(stack_b.v);
	return (0);
}
