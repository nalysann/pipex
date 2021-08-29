/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:50:17 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:50:17 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "pf_handle_placeholder.h"

#include "ft_string.h"

char	*handle_string(t_fields *fields, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (fields->precision != GET_DEFAULT && len > fields->precision)
		len = fields->precision;
	return (ft_strndup(str, len));
}
