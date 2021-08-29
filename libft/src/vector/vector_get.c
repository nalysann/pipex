/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:18 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:55:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdio.h"
#include "ft_vector.h"

void	*vector_get(t_vector *vector, size_t idx)
{
	if (idx >= vector->size)
		ft_error(VECTOR_INVALID_INDEX_MSG, E_VECTOR_ERROR);
	return (vector->data[idx]);
}
