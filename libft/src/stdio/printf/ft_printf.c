/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:48:49 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:48:50 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "pf_buffer.h"
#include "pf_handle_placeholder.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int					ret;
	static t_buffer		buf;

	ret = 0;
	check_buffer(&buf, fd);
	while (*format)
	{
		if (*format != '%')
		{
			add_to_buffer(&buf, format, 1);
			++ret;
			++format;
		}
		else
			ret += handle_placeholder(&format, ap, &buf);
	}
	if (FLUSH_POLICY == UPON_CALL)
		flush_buffer(&buf, fd);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
