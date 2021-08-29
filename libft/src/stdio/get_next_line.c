/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:51:42 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:51:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_string.h"
#include "in_get_next_line.h"

static char	*process_buffer(char **buffer, char *endl)
{
	char	*str;
	char	*tmp;

	if (endl)
	{
		str = ft_strndup(*buffer, endl - *buffer);
		tmp = *buffer;
		*buffer = ft_strdup(endl + 1);
	}
	else
	{
		str = *buffer;
		tmp = NULL;
		*buffer = NULL;
	}
	free(tmp);
	return (str);
}

static void	gnl_internal(int fd, char **buffers, ssize_t *ret, char **endl)
{
	char	buf[GNL_BUF_SIZE + 1];
	char	*tmp;

	if (buffers[fd] == NULL)
		buffers[fd] = ft_strnew(0);
	*endl = ft_strchr(buffers[fd], '\n');
	*ret = read(fd, buf, GNL_BUF_SIZE);
	while (*endl == NULL && ret > 0)
	{
		buf[*ret] = '\0';
		tmp = buffers[fd];
		buffers[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
		{
			*endl = ft_strchr(buffers[fd], '\n');
			if (*endl)
				break ;
		}
		*ret = read(fd, buf, GNL_BUF_SIZE);
	}
}

int	get_next_line(int fd, char **line)
{
	static char		*buffers[GNL_FD_MAX];
	ssize_t			ret;
	char			*endl;

	gnl_internal(fd, buffers, &ret, &endl);
	if (*buffers[fd])
		*line = process_buffer(&buffers[fd], endl);
	else
		*line = NULL;
	if (*line == NULL)
		free(buffers[fd]);
	if (*line)
		return (1);
	else
		return ((int)ret);
}
