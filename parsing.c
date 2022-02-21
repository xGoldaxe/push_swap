/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:09:46 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/21 10:29:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_error(int *stackv)
{
	free(stackv);
	write(2, "Error\n", 6);
	return (0);
}

int	is_integer(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size > 11)
		return (0);
	if (size == 11)
	{
		if (str[0] != '-')
			return (0);
		if (ft_strcmp(&str[1], "2147483648") > 0)
			return (0);
	}
	if (size == 10)
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	return (1);
}

int	ft_onlynumber(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	if (str[i] == '-')
		++i;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		++i;
	}
	return (1);
}

int	ft_check_double(int *stackv, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stackv[i] == nbr)
			return (1);
		++i;
	}
	return (0);
}

int	*store_stack(char **stack_str, int stack_size)
{
	int	i;
	int	*stackv;

	stackv = malloc(sizeof(int) * stack_size);
	if (!stackv)
		return (NULL);
	i = 0;
	while (--stack_size >= 0)
	{
		if (ft_onlynumber(stack_str[stack_size]) == 0
			|| is_integer(stack_str[stack_size]) == 0
			|| ft_check_double(stackv, i,
				ft_atoi(stack_str[stack_size])) == 1)
			return (parse_error(stackv), NULL);
		stackv[i] = ft_atoi(stack_str[stack_size]);
		++i;
	}
	return (stackv);
}
