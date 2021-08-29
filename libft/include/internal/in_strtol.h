/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:24 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:24 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_STRTOL_H
# define IN_STRTOL_H

struct s_strtol
{
	const char		*str;
	int				base;
	int				sign;
	int				c;
	int				any;
	unsigned long	res;
};

typedef struct s_strtol		t_strtol;

#endif
