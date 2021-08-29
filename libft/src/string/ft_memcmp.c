/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:56:48 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:56:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1_uchar;
	const unsigned char		*s2_uchar;

	if (s1 == s2)
		return (0);
	s1_uchar = s1;
	s2_uchar = s2;
	while (n--)
		if (*s1_uchar++ != *s2_uchar++)
			return (*--s1_uchar - *--s2_uchar);
	return (0);
}
