/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:00:00 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 14:00:00 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstartswith(const char *str, const char *prefix)
{
	while (*str == *prefix)
	{
		if (*prefix == '\0')
			break ;
		++str;
		++prefix;
	}
	return (*prefix == '\0');
}
