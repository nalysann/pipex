/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_placeholder.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:39:49 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:39:49 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_PLACEHOLDER_H
# define PF_PRINT_PLACEHOLDER_H

# include <stdarg.h>

# include "pf_buffer.h"
# include "pf_handle_placeholder.h"

int		print_placeholder(t_fields *fields, va_list ap, t_buffer *buf);

#endif
