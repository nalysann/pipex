/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:55:37 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 15:08:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_vector.h"

void	vector_reverse(t_vector *vector)
{
	size_t	beg;
	size_t	end;

	beg = 0;
	end = vector->size;
	while (beg < --end)
		ft_swap(vector->data[beg++], vector->data[end], sizeof(void *));
}
