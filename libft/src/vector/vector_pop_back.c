/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:26 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:55:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_vector.h"

void	*vector_pop_back(t_vector *vector)
{
	if (vector->size == 0)
		ft_error(EMPTY_VECTOR_POP_MSG, E_VECTOR_ERROR);
	return (vector->data[--vector->size]);
}
