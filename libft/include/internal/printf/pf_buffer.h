/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:38:49 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:38:49 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_BUFFER_H
# define PF_BUFFER_H

# include <stddef.h>

# define BUF_SIZE 4096
# define UPON_CALL 0
# define UPON_EXIT 1
# define FLUSH_POLICY UPON_CALL

struct s_buffer
{
	int		fd;
	char	str[BUF_SIZE + 1];
	size_t	len;
};

typedef struct s_buffer		t_buffer;

void	flush_buffer(t_buffer *buf, int fd);
void	check_buffer(t_buffer *buf, int fd);
void	add_to_buffer(t_buffer *buf, const char *str, size_t len);

#endif
