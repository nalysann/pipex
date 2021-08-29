/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:59:28 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:59:28 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	len;

	len = ft_strnlen(src, n);
	if (len != n)
		ft_memset(dst + len, 0, n - len);
	return (ft_memcpy(dst, src, len));
}
