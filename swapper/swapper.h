/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:34:44 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/04 12:46:51 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPPER_H
# define SWAPPER_H

# include	"unistd.h"
# include	<stdio.h>

typedef struct s_stack
{
	int	size;
	int	*v;
}	t_stack;

/* swapper macro */
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

/* swapper */
//swap
int	swap_sa(t_stack *stack_a, t_stack *stack_b);
int	swap_sb(t_stack *stack_a, t_stack *stack_b);
int	swap_ss(t_stack *stack_a, t_stack *stack_b);
//push
int	push_pa(t_stack *stack_a, t_stack *stack_b);
int	push_pb(t_stack *stack_a, t_stack *stack_b);
//rotate
int	rotate_ra(t_stack *stack_a, t_stack *stack_b);
int	rotate_rb(t_stack *stack_a, t_stack *stack_b);
int	rotate_rr(t_stack *stack_a, t_stack *stack_b);
//reverse
int	reverse_rra(t_stack *stack_a, t_stack *stack_b);
int	reverse_rrb(t_stack *stack_a, t_stack *stack_b);
int	reverse_rrr(t_stack *stack_a, t_stack *stack_b);

/* MAIN FUNCTIONS */
int	operation(int operation_index, t_stack *stack_a, t_stack *stack_b);

#endif