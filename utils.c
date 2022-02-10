/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:42:18 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 18:32:21 by pleveque         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
