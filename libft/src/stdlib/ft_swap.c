/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:53:45 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:53:45 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *a, void *b, size_t size)
{
	unsigned char	*a_uchar;
	unsigned char	*b_uchar;
	unsigned char	tmp;

	a_uchar = a;
	b_uchar = b;
	while (size--)
	{
		tmp = *a_uchar;
		*a_uchar++ = *b_uchar;
		*b_uchar++ = tmp;
	}
}
