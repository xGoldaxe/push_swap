#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#define INT_INF 2147483647

int search_replace(int *lis, int left, int right, int key) {
	int mid;

	mid = (left+right)/2;
	while (left <= right)
	{
		if (lis[mid] > key)
				right = mid - 1;
		else if (lis[mid] == key)
				return mid;
		else if (mid+1 <= right && lis[mid+1] >= key)
		{
			lis[mid+1] = key;
			return mid+1;
		}		
		else
			left = mid + 1;
		mid = (left+right)/2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return mid;
	}
	lis[mid+1] = key;
	return mid+1;
}

t_stack *lis(int *A, int size)
{
	int	i;
	int	tmp;
	t_stack *res;
	int	*LIS;
	int	*index;

	res = malloc(sizeof(t_stack));
	LIS = malloc(sizeof(int) * size);
	index = malloc(sizeof(int) * size);
	if (!res || !LIS || !index)
		return (free(res), free(LIS), free(index), NULL);
	res->size = -1;
	index[0] = 0;
	LIS[0] = A[size - 1];
	i = 0;
	while (++i < size)
		LIS[i] = INT_INF;
	i = -1;
	while (++i < size)
	{
		index[i] = search_replace(LIS, 0, i, A[size - i -1]);
		if (res->size < index[i])
			res->size = index[i];
	}
	res->v = (int *)malloc((res->size + 1) * sizeof(int));
	tmp = res->size;
	i = size;
	while (--i >= 0)
	{
		if (index[i] == tmp) {
			res->v[tmp] = A[size - i - 1];
			--tmp;
		}
	}
	res->size += 1;
	// priting lis
	// printf("LIS: ");
	// for (i = 0; i < res->size+1; ++i) {
	// 	printf("%d ", res->v[i]);
	// }
	// printf("\n");
	// printf("lis size: %d\n", res->size + 1);
	return (res);
}

t_stack	*stack_to_lis(t_stack *stack)
{
	t_stack	*dst;

	dst = lis(stack->v, stack->size);
	return (dst);
}
