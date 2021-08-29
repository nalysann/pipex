/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:04 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:04 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_UTILS_H
# define PF_UTILS_H

# include <stddef.h>

# include "pf_bigint.h"

void	ft_atoi_skip(const char **str);
size_t	get_length_signed(long long nbr, long long base);
void	itoa_base_signed(long long nbr, char *base, char *result);
size_t	get_length_unsigned(unsigned long long nbr, unsigned long long base);
void	itoa_base_unsigned(unsigned long long nbr, char *base, char *result);
void	ulltoa(unsigned long long value, t_string *string);
void	print_block_helper(t_bigint *bi, int i, unsigned int *base, int *k);

#endif
