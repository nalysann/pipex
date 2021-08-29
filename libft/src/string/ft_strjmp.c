/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:58:09 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:58:09 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moves the underlying string one position after
** the end of the current token, returns the
** pointer to the beginning of the current token
*/

char	*ft_strjmp(const char **s, char sep)
{
	const char	*beg;
	const char	*end;

	end = *s;
	while (*end == sep)
		++end;
	beg = end;
	while (*end && *end != sep)
		++end;
	*s = end;
	return ((char *)beg);
}
