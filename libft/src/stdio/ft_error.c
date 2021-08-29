/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:51:01 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:51:01 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_string.h"
#include "in_error.h"

void	ft_error(const char *msg, int code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(code);
}

void	ft_error2(const char *first, const char *second, int code)
{
	char	error_buf[ERROR_BUF_SIZE + 1];

	ft_strncpy(error_buf, first, ERROR_BUF_SIZE);
	ft_strncat(error_buf, ": ", ERROR_BUF_SIZE);
	ft_strncat(error_buf, second, ERROR_BUF_SIZE);
	error_buf[ERROR_BUF_SIZE] = '\0';
	ft_error(error_buf, code);
}

void	ft_error3(const char *s1, const char *s2, const char *s3, int code)
{
	char	error_buf[ERROR_BUF_SIZE + 1];

	ft_strncpy(error_buf, s1, ERROR_BUF_SIZE);
	ft_strncat(error_buf, ": ", ERROR_BUF_SIZE);
	ft_strncat(error_buf, s2, ERROR_BUF_SIZE);
	ft_strncat(error_buf, ": ", ERROR_BUF_SIZE);
	ft_strncat(error_buf, s3, ERROR_BUF_SIZE);
	error_buf[ERROR_BUF_SIZE] = '\0';
	ft_error(error_buf, code);
}

void	ft_perror(const char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	ft_perror2(const char *first, const char *second, int code)
{
	char	error_buf[ERROR_BUF_SIZE + 1];

	ft_strncpy(error_buf, first, ERROR_BUF_SIZE);
	ft_strncat(error_buf, ": ", ERROR_BUF_SIZE);
	ft_strncat(error_buf, second, ERROR_BUF_SIZE);
	error_buf[ERROR_BUF_SIZE] = '\0';
	ft_perror(error_buf, code);
}
