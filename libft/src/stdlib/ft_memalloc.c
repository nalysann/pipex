/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:52:51 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:52:51 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_string.h"

void	*ft_memalloc(size_t size)
{
	void	*data;

	data = xmalloc(size);
	ft_memset(data, 0, size);
	return (data);
}
