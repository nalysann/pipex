/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_asterisk.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:38:57 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:38:57 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_ASTERISK_H
# define PF_HANDLE_ASTERISK_H

# include <stdarg.h>

# include "pf_handle_placeholder.h"

void	handle_asterisk(t_fields *fields, va_list ap);

#endif
