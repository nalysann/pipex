/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:46 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 15:06:38 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_vector.h"

void	vector_sort(t_vector *vector, int (*cmp)(const void *, const void *))
{
	ft_qsort(vector->data, vector->size, sizeof(void *), cmp);
}
