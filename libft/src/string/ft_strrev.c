/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:59:53 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:59:53 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

void	ft_strrev(char *s)
{
	char	*p;

	p = s + ft_strlen(s);
	while (s < --p)
		ft_swap(s++, p, sizeof(char));
}
