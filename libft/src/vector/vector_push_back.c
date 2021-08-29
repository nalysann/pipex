/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:30 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 15:10:21 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_vector.h"

void	vector_push_back(t_vector *vector, void *item)
{
	void	**new_data;
	size_t	new_capacity;

	if (vector->size == vector->capacity)
	{
		if (vector->capacity == 0)
			new_capacity = 1;
		else
			new_capacity = vector->capacity * 2;
		new_data = (void **)xmalloc(sizeof(void *) * new_capacity);
		ft_memmove(new_data, vector->data, sizeof(void *) * vector->capacity);
		free(vector->data);
		vector->data = new_data;
		vector->capacity = new_capacity;
	}
	vector->data[vector->size++] = item;
}
