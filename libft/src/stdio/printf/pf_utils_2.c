/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:50:48 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:50:48 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "pf_bigint.h"
#include "pf_utils.h"

void	ulltoa(unsigned long long value, t_string *string)
{
	size_t	length;
	size_t	i;

	length = get_length_unsigned(value, 10);
	i = 0;
	while (i < length)
	{
		string->str[string->len + length - 1 - i] = (char)(value % 10 + '0');
		++i;
		value /= 10;
	}
	string->len += length;
}

void	print_block_helper(t_bigint *bi, int i, unsigned int *base, int *k)
{
	*base = 1;
	if (i == (int)bi->size - 1)
	{
		*k = (int)get_length_unsigned(bi->blocks[i], 10);
		while (--k)
			*base = *base * 10;
	}
	else
		*base = 100000000;
}
