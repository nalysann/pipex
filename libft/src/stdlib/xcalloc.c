/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:54:07 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:54:07 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_string.h"

void	*xcalloc(size_t count, size_t size)
{
	void	*data;

	data = xmalloc(count * size);
	ft_memset(data, 0, count * size);
	return (data);
}
