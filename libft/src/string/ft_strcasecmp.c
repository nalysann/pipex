/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:57:19 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:57:19 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	const unsigned char		*s1_uchar;
	const unsigned char		*s2_uchar;
	int						res;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	if (s1_uchar == s2_uchar)
		return (0);
	while (1)
	{
		res = ft_tolower(*s1) - ft_tolower(*s2++);
		if (res != 0 || *s1_uchar++ == '\0')
			break ;
	}
	return (res);
}
