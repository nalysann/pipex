/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:22 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 15:13:37 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_vector.h"

t_vector	vector_on_stack(void)
{
	t_vector	vector;

	vector.data = NULL;
	vector.size = 0;
	vector.capacity = 0;
	return (vector);
}

t_vector	*vector_on_heap(void)
{
	t_vector	*vector;

	vector = (t_vector *)xmalloc(sizeof(t_vector));
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
	return (vector);
}
