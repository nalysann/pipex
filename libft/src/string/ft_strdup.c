/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:57:49 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:57:49 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strdup(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	return ((char *)ft_memcpy(xmalloc(len + 1), s, len + 1));
}
