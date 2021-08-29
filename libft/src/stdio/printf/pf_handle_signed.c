/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:50:13 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:50:13 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_stdlib.h"
#include "ft_string.h"

#include "pf_handle_length.h"
#include "pf_handle_placeholder.h"
#include "pf_utils.h"

char	*handle_signed(t_fields *fields, va_list ap)
{
	char	*result;
	char	str[42];
	int		len;
	int		zeros;
	int		sign;

	itoa_base_signed(get_signed(ap, (int)fields->length), DEC_DIGITS, str);
	len = (int)ft_strlen(str);
	sign = (*str == '-');
	if (len == 1 && *str == '0' && fields->precision == 0)
		return (ft_strnew(0));
	if (fields->precision > len - sign)
		result = ft_strnew(60 + fields->precision + sign);
	else
		result = ft_strnew(60 + len);
	ft_strcpy(result, str);
	zeros = fields->precision - (len - sign);
	if (fields->precision != GET_DEFAULT && zeros > 0)
	{
		ft_memmove(result + sign + zeros, result + sign, len - sign + 1);
		ft_memset(result + sign, '0', zeros);
	}
	return (result);
}
