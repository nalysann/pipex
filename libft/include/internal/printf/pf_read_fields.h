/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_fields.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:39:54 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:39:54 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_READ_FIELDS_H
# define PF_READ_FIELDS_H

# include "pf_handle_placeholder.h"

void	read_flags(const char **format, t_fields *fields);
void	read_width(const char **format, t_fields *fields);
void	read_precision(const char **format, t_fields *fields);
void	read_length(const char **format, t_fields *fields);
void	read_type(const char **format, t_fields *fields);

#endif
