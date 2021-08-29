/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:55 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

double			ft_fabs(double x);
float			ft_fabsf(float x);
long double		ft_fabsl(long double x);
double			ft_fmax(double x, double y);
float			ft_fmaxf(float x, float y);
long double		ft_fmaxl(long double x, long double y);
double			ft_fmin(double x, double y);
float			ft_fminf(float x, float y);
long double		ft_fminl(long double x, long double y);
long long		ft_llmax(long long i, long long j);
long long		ft_llmin(long long i, long long j);
long			ft_lmax(long i, long j);
long			ft_lmin(long i, long j);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

#endif
