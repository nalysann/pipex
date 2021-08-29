/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:57:41 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:57:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

size_t	ft_strcnt(const char *s, char sep)
{
	size_t	cnt;

	if (*s == '\0')
		return (0);
	if (sep == '\0')
		return (1);
	cnt = 0;
	while (*ft_strjmp(&s, sep) != '\0')
		++cnt;
	return (cnt);
}
