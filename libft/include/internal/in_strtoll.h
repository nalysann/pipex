/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_strtoll.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:31 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:31 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_STRTOLL_H
# define IN_STRTOLL_H

struct s_strtoll
{
	const char			*str;
	int					base;
	int					sign;
	int					c;
	int					any;
	unsigned long long	res;
};

typedef struct s_strtoll	t_strtoll;

#endif
