/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:58:28 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:58:28 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "in_error.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > SIZE_MAX - len1 - 1)
		ft_error(ALLOC_JOIN_MSG, E_ALLOC);
	new = (char *)xmalloc(len1 + len2 + 1);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2 + 1);
	return (new);
}

char	*ft_strjoin_sep(const char *s1, const char *s2, const char *sep)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	len_sep;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len_sep = ft_strlen(sep);
	if (len_sep > SIZE_MAX - len1 - 1 || len2 > SIZE_MAX - len1 - len_sep - 1)
		ft_error(ALLOC_JOIN_MSG, E_ALLOC);
	new = (char *)xmalloc(len1 + len_sep + len2 + 1);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, sep, len_sep);
	ft_memcpy(new + len1 + len_sep, s2, len2 + 1);
	return (new);
}
