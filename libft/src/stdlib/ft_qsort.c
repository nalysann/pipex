/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:53:06 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:53:06 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"

static void	*hoare(void *left, void *right, size_t size,
				int (*cmp)(const void *, const void *))
{
	void	*pivot;
	void	*i;
	void	*j;

	pivot = left + (right - left) / size / 2 * size;
	i = left - size;
	j = right + size;
	while (1)
	{
		i += size;
		while (cmp(i, pivot) < 0)
			i += size;
		j -= size;
		while (cmp(j, pivot) > 0)
			j -= size;
		if (i >= j)
			return (j);
		ft_swap(i, j, size);
	}
}

static void	quicksort(void *left, void *right, size_t size,
				int (*cmp)(const void *, const void *))
{
	void	*pivot;

	if (left < right)
	{
		pivot = hoare(left, right, size, cmp);
		quicksort(left, pivot, size, cmp);
		quicksort(pivot + size, right, size, cmp);
	}
}

void	ft_qsort(void *data, size_t len, size_t size,
				int (*cmp)(const void *, const void *))
{
	void	*left;
	void	*right;

	if (len == 0)
		return ;
	left = data;
	right = data + (len - 1) * size;
	quicksort(left, right, size, cmp);
}
