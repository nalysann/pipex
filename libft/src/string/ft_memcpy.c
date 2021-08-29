/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:56:52 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:56:52 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dst_uchar;
	const unsigned char		*src_uchar;

	if (dst == src)
		return (dst);
	dst_uchar = dst;
	src_uchar = src;
	while (n--)
		*dst_uchar++ = *src_uchar++;
	return (dst);
}
