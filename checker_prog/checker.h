/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:34:44 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 19:54:19 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include   <limits.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	"../swapper/swapper.h"

/* PARSING */

int		parse_error(int *stackv);
int		is_integer(char *str);
int		ft_onlynumber(char *str);
int		*store_stack(char **stack_str, int stack_size);

/* STACK */
int		verify_sorted_stack(t_stack *stack);
int		clean_exit(t_stack *stack_a, t_stack *stack_b);

/* UTILS */
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);

#endif