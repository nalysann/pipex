/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:59:57 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:59:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_string.h"

char	**ft_strsplit(const char *s, char sep)
{
	char	**split;
	char	*p;
	size_t	n;
	size_t	i;

	n = ft_strcnt(s, sep);
	split = (char **)xmalloc((n + 1) * sizeof(char *));
	i = 0;
	while (i < n)
	{
		p = ft_strjmp(&s, sep);
		split[i++] = ft_strndup(p, s - p);
	}
	split[n] = NULL;
	return (split);
}
