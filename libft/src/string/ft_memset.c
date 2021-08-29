/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:57:07 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:57:07 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uchar_ptr;
	unsigned char	uc;

	uchar_ptr = b;
	uc = (unsigned char)c;
	while (len--)
		*uchar_ptr++ = uc;
	return (b);
}
