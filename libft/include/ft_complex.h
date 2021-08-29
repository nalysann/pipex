/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:40 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

struct s_complex
{
	double	re;
	double	im;
};

typedef struct s_complex	t_complex;

t_complex	complex_on_stack(double re, double im);
t_complex	*complex_on_heap(double re, double im);
void		complex_set(t_complex *this, double re, double im);

double		complex_abs2(const t_complex *this);

t_complex	complex_add(const t_complex *first, const t_complex *second);
t_complex	complex_sub(const t_complex *first, const t_complex *second);
t_complex	complex_mul(const t_complex *first, const t_complex *second);
t_complex	complex_div(const t_complex *first, const t_complex *second);

void		complex_iadd(t_complex *this, const t_complex *other);
void		complex_isub(t_complex *this, const t_complex *other);
void		complex_imul(t_complex *this, const t_complex *other);
void		complex_idiv(t_complex *this, const t_complex *other);

#endif
