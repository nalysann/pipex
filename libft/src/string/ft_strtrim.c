/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:00:08 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 14:00:08 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

char	*ft_strtrim(const char *s)
{
	size_t	beg;
	size_t	end;

	beg = 0;
	end = ft_strlen(s);
	if (end-- > 0)
	{
		while ((s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n')
			&& beg <= end)
			++beg;
		while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			&& beg <= end)
			--end;
	}
	return (ft_strndup(s + beg, end - beg + 1));
}
