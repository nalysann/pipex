/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:41:01 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:41:01 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);

int		get_next_line(int fd, char **line);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);

void	ft_error(const char *msg, int code);
void	ft_error2(const char *first, const char *second, int code);
void	ft_error3(const char *s1, const char *s2, const char *s3, int code);
void	ft_perror(const char *msg, int code);
void	ft_perror2(const char *first, const char *second, int code);

#endif
