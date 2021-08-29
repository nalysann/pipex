/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:38:36 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:38:42 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_BIGINT_H
# define PF_BIGINT_H

# include <stddef.h>

# define BIGINT_BASE 1000000000
# define BIGINT_MAX_BLOCKS 1300
# define BIGINT_BLOCK_SIZE 9

struct s_bigint
{
	unsigned long long	blocks[BIGINT_MAX_BLOCKS];
	unsigned int		size;
};

typedef struct s_bigint		t_bigint;

struct s_string
{
	char			str[BIGINT_MAX_BLOCKS * BIGINT_BLOCK_SIZE];
	unsigned int	len;
};

typedef struct s_string		t_string;

void	bigint_add(t_bigint *this, t_bigint *other);
void	bigint_add_ull(t_bigint *this, unsigned long long other);
void	bigint_mul_ull(t_bigint *this, unsigned long long other);
void	bigint_power_of_five(t_bigint *this, unsigned int power);

#endif
