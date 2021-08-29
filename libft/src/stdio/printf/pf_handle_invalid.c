/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_invalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:49:40 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:49:40 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_stdlib.h"
#include "ft_string.h"

#include "pf_handle_placeholder.h"

char	*handle_invalid(t_fields *fields, va_list ap)
{
	char	*result;

	result = ft_strnew(0);
	ft_memset(fields, 0, sizeof(*fields));
	(void)ap;
	return (result);
}
