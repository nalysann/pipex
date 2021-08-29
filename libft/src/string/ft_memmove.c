/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:56:59 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:56:59 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*dst_uchar;
	const unsigned char		*src_uchar;

	if (src >= dst || dst >= src + n)
		return (ft_memcpy(dst, src, n));
	dst_uchar = dst + n;
	src_uchar = src + n;
	while (n--)
		*--dst_uchar = *--src_uchar;
	return (dst);
}
