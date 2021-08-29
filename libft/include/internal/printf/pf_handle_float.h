/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_float.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:39:32 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:39:32 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_FLOAT_H
# define PF_HANDLE_FLOAT_H

# include <stdarg.h>

# include "pf_handle_placeholder.h"

# define EXPONENT_SHIFT 16383

union u_extended
{
	long double				value;
	struct
	{
		unsigned long long	mantissa : 64;
		unsigned			exponent : 15;
		unsigned			sign : 1;
	}						s_;
};

typedef union u_extended	t_extended;

char	*handle_float(t_fields *fields, va_list ap);

#endif
