/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:14 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:55:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_vector.h"

void	vector_free(t_vector *vector)
{
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
}

void	vector_free_deep(t_vector *vector, void (*f)(void*))
{
	size_t	i;

	i = 0;
	while (i < vector->size)
		f(vector->data[i++]);
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
}
