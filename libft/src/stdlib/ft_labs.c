/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:52:42 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:52:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_labs(long i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}