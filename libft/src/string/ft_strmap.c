/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:58:49 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:58:49 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = (char *)xmalloc(len + 1);
	i = 0;
	while (i < len)
	{
		new[i] = f(s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
