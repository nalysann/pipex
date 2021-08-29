/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_placeholder.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:39:38 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:39:38 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_PLACEHOLDER_H
# define PF_HANDLE_PLACEHOLDER_H

# include <stdarg.h>

# include "pf_buffer.h"

# define SUPPORTED_FLAGS "#0-+ "
# define FLAG_HASH 1U
# define FLAG_ZERO 2U
# define FLAG_MINUS 4U
# define FLAG_PLUS 8U
# define FLAG_SPACE 16U

# define GET_DEFAULT (-1)
# define GET_ARGUMENT (-2)

# define ZERO_PRECISION 0
# define DEFAULT_PRECISION 6

# define LENGTH_MODIFIERS_SIZE 8
# define LENGTH_HH 1U
# define LENGTH_H 2U
# define LENGTH_LL_LOWER 4U
# define LENGTH_L_LOWER 8U
# define LENGTH_J 16U
# define LENGTH_T 32U
# define LENGTH_Z 64U
# define LENGTH_L_UPPER 128U
# define LENGTH_DEFAULT 2147483648U

# define TYPES_SIZE 12
# define SUPPORTED_TYPES "cspdiouxXbf%"
# define INTEGER_TYPES "diouxXb"
# define INVALID_TYPE '\0'

# define BIN_DIGITS "01"
# define OCT_DIGITS "01234567"
# define DEC_DIGITS "0123456789"
# define HEXL_DIGITS "0123456789abcdef"
# define HEXU_DIGITS "0123456789ABCDEF"

struct s_fields
{
	unsigned int	flags;
	int				width;
	int				precision;
	unsigned int	length;
	char			type;
};

typedef struct s_fields		t_fields;

typedef char*				(*t_type_handler)(t_fields *fields, va_list ap);

int		handle_placeholder(const char **format, va_list ap, t_buffer *buf);

#endif
