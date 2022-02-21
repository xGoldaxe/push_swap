/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:21:12 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/21 10:21:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_size(char **splited)
{
	int	i;

	if (!splited)
		return (0);
	i = 0;
	while (splited[i])
		++i;
	return (i);
}

int	free_split(char **splited)
{
	int	i;

	if (!splited)
		return (-1);
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		++i;
	}
	free(splited);
	return (i);
}
