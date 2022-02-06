/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:34:44 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/06 17:04:00 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include   <limits.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	"swapper/swapper.h"

/* STACK UTILS */
int		verify_sorted_stack(t_stack *stack);
int		stack_lower(t_stack *stack);
int		stack_higher(t_stack *stack);
int		sort_stack(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack	*stack);
int 	stack_merge(t_stack *stack_a, t_stack *stack_b);
int 	stack_bubble(t_stack *stack_a, t_stack *stack_b);
int     stack_find_insert_index(t_stack *stack, int value);
int	    stack_insert(t_stack *stack_a, t_stack *stack_b);

/* SORT ALGO */
int		sort_three(t_stack *stack_a, t_stack *stack_b);
int		sort_five(t_stack *stack_a, t_stack *stack_b);
int		sort_regular(t_stack *stack_a, t_stack *stack_b);

/* UTILS */
int		ft_atoi(const char *str);
int		is_higher(int a, int b);
int		is_lower(int a, int b);
t_stack *stack_to_lis(t_stack *stack);

#endif