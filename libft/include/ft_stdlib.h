/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:41:08 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:41:08 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

void		free_split(char **split);
int			ft_abs(int i);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
size_t		ft_intlen(int n);
char		*ft_itoa(int n);
long		ft_labs(long i);
long long	ft_llabs(long long i);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_qsort(void *data, size_t len, size_t size,
				int (*cmp)(const void *, const void *));
void		ft_strdel(char **as);
char		*ft_strnew(size_t size);
long		ft_strtol(const char *str, char **endptr, int base);
long long	ft_strtoll(const char *str, char **endptr, int base);
void		ft_swap(void *a, void *b, size_t size);
void		*xcalloc(size_t count, size_t size);
void		*xmalloc(size_t size);

#endif
