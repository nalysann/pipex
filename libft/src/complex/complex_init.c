/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:42:53 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:42:53 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include "ft_stdlib.h"

t_complex	complex_on_stack(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_complex	*complex_on_heap(double re, double im)
{
	t_complex	*z;

	z = (t_complex *)xmalloc(sizeof(t_complex));
	z->re = re;
	z->im = im;
	return (z);
}

void	complex_set(t_complex *this, double re, double im)
{
	this->re = re;
	this->im = im;
}
