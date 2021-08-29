/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:56:40 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:56:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_uchar;
	const unsigned char		*src_uchar;
	unsigned char			uc;

	dst_uchar = dst;
	src_uchar = src;
	uc = (unsigned char)c;
	while (n--)
	{
		*dst_uchar++ = *src_uchar++;
		if (dst_uchar[-1] == uc)
			return (dst_uchar);
	}
	return (NULL);
}
