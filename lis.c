/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:17:06 by pleveque          #+#    #+#             */
/*   Updated: 2022/02/10 18:02:13 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#define INT_INF 2147483647

int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}		
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

t_stack	*lis(int *A, int size)
{
	int		i;
	int		tmp;
	t_stack	*res;
	int		*lis;
	int		*index;

	res = malloc(sizeof(t_stack));
	lis = malloc(sizeof(int) * size);
	index = malloc(sizeof(int) * size);
	if (!res || !lis || !index)
		return (free(res), free(lis), free(index), NULL);
	res->size = -1;
	index[0] = 0;
	lis[0] = A[size - 1];
	i = 0;
	while (++i < size)
		lis[i] = INT_INF;
	i = -1;
	while (++i < size)
	{
		index[i] = search_replace(lis, 0, i, A[size - i -1]);
		if (res->size < index[i])
			res->size = index[i];
	}
	res->v = (int *)malloc((res->size + 1) * sizeof(int));
	tmp = res->size;
	i = size;
	while (--i >= 0)
	{
		if (index[i] == tmp)
		{
			res->v[tmp] = A[size - i - 1];
			--tmp;
		}
	}
	res->size += 1;
	free(lis);
	free(index);
	return (res);
}

t_stack	*stack_to_lis(t_stack *stack)
{
	t_stack	*dst;

	dst = lis(stack->v, stack->size);
	return (dst);
}
