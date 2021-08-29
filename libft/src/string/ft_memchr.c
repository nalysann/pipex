/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:56:44 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:56:44 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_uchar;
	unsigned char		uc;

	s_uchar = s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*s_uchar == uc)
			return ((void *)s_uchar);
		++s_uchar;
	}
	return (NULL);
}
