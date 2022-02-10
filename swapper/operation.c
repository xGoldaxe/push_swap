/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:22:19 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 17:15:53 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swapper.h"

int	operation_print(int operation_index)
{	
	static char	value[40] = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	int			i;
	int			actual_word;

	if (operation_index >= 0 && operation_index <= 11)
	{
		i = 0;
		actual_word = 0;
		while (actual_word < operation_index)
		{
			if (value[i] == '\n')
				++actual_word;
			++i;
		}
		--i;
		while (value[++i] && value[i] != '\n')
			write(1, &value[i], 1);
		write(1, "\n", 1);
		return (0);
	}
	return (-1);
}

int	operation_static(int operation_index, int *call, int *print_text)
{
	if (operation_index == -1 || operation_index == -3 || operation_index == -4)
	{
		if (operation_index == -1)
			*call = 0;
		else if (operation_index == -3)
			*print_text = 0;
		else if (operation_index == -4)
			*print_text = 1;
		return (0);
	}
	else if (operation_index == -2)
		return (*call);
	return (-1);
}

int	operation(int operation_index, t_stack *stack_a, t_stack *stack_b)
{
	static int	(*swap[11])(t_stack *stack_a, t_stack *stack_b) = {
		&swap_sa, &swap_sb, &swap_ss, &push_pa, &push_pb, &rotate_ra,
		&rotate_rb, &rotate_rr, &reverse_rra, &reverse_rrb, &reverse_rrr
	};
	static int	call = 0;
	static int	print_text = 1;

	if (operation_index < 0)
		return (operation_static(operation_index, &call, &print_text));
	++call;
	if (operation_index >= 0 && operation_index <= 11)
	{
		if (print_text)
			operation_print(operation_index);
		return (swap[operation_index](stack_a, stack_b));
	}
	return (-2);
}
