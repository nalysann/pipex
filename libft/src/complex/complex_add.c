/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:42:43 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:42:43 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	complex_add(const t_complex *first, const t_complex *second)
{
	t_complex	res;

	res.re = first->re + second->re;
	res.im = first->im + second->im;
	return (res);
}

void	complex_iadd(t_complex *this, const t_complex *other)
{
	this->re += other->re;
	this->im += other->im;
}
