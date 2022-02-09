/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:34:44 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/09 15:26:52 by pleveque         ###   ########.fr       */
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

typedef struct s_operations
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}   t_operations;

/* STACK UTILS */
int				verify_sorted_stack(t_stack *stack);
int				stack_lower(t_stack *stack);
int				stack_higher(t_stack *stack);
int				sort_stack(t_stack *stack_a, t_stack *stack_b);
void			print_stack(t_stack	*stack);
int 			stack_merge(t_stack *stack_a, t_stack *stack_b);
int 			stack_bubble(t_stack *stack_a, t_stack *stack_b);
int				stack_find_insert_index(t_stack *stack, int value);
int				stack_insert(t_stack *stack_a, t_stack *stack_b);
t_operations	*get_number_operation(t_stack *stack_a, int value, t_operations *operations);
int				push_out_from_stack(t_stack *stack_a, t_stack *stack_b, t_stack *stack_lis);
/* SORT ALGO */
int				sort_three(t_stack *stack_a, t_stack *stack_b);
int				sort_five(t_stack *stack_a, t_stack *stack_b);
int				sort_regular(t_stack *stack_a, t_stack *stack_b);

/* UTILS */
int				ft_atoi(const char *str);
int				is_higher(int a, int b);
int				is_lower(int a, int b);
int				ft_abs(int nbr);
t_stack			*stack_to_lis(t_stack *stack);

#endif