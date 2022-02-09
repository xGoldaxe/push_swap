/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:42:18 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/09 15:03:12 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(int a, int b)
{
	return (a < b);
}

int	is_higher(int a, int b)
{
	return (a > b);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}