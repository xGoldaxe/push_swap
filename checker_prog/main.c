/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:24:55 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 20:21:45 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	proceed_operation(char *op, t_stack *stack_a, t_stack *stack_b)
{
	operation(-3, 0, 0);
	if (ft_strcmp(op, "pa\n") == 0)
		return (operation(PA, stack_a, stack_b));
	else if (ft_strcmp(op, "pb\n") == 0)
		return (operation(PB, stack_a, stack_b));
	else if (ft_strcmp(op, "sa\n") == 0)
		return (operation(SA, stack_a, stack_b));
	else if (ft_strcmp(op, "sb\n") == 0)
		return (operation(SB, stack_a, stack_b));
	else if (ft_strcmp(op, "ss\n") == 0)
		return (operation(SS, stack_a, stack_b));
	else if (ft_strcmp(op, "ra\n") == 0)
		return (operation(RA, stack_a, stack_b));
	else if (ft_strcmp(op, "rb\n") == 0)
		return (operation(RB, stack_a, stack_b));
	else if (ft_strcmp(op, "rr\n") == 0)
		return (operation(RR, stack_a, stack_b));
	else if (ft_strcmp(op, "rra\n") == 0)
		return (operation(RRA, stack_a, stack_b));
	else if (ft_strcmp(op, "rrb\n") == 0)
		return (operation(RRB, stack_a, stack_b));
	else if (ft_strcmp(op, "rrr\n") == 0)
		return (operation(RRR, stack_a, stack_b));
	return (-666);
}

void	read_stdin_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	(void)stack_a;
	(void)stack_b;
	line = get_next_line(0);
	while (line)
	{
		if (proceed_operation(line, stack_a, stack_b) == -666)
		{
			free(line);
			free(stack_a->v);
			free(stack_b->v);
			write(2, "Error\n", 6);
			exit(0);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	stack_a.size = argc - 1;
	stack_a.v = store_stack(&argv[1], stack_a.size);
	stack_b.v = malloc(sizeof(int) * stack_a.size);
	stack_b.size = 0;
	if (!stack_a.v || !stack_b.v)
		clean_exit(&stack_a, &stack_b);
	read_stdin_operations(&stack_a, &stack_b);
	if (verify_sorted_stack(&stack_a) == 1 && stack_b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
