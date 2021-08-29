/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:41:16 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 14:59:58 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>
# include <stdint.h>

# define EMPTY_VECTOR_POP_MSG "Pop from the empty vector"
# define VECTOR_INVALID_INDEX_MSG "Vector index out of range"
# define E_VECTOR_ERROR 1

struct s_vector
{
	void	**data;
	size_t	size;
	size_t	capacity;
};

typedef struct s_vector		t_vector;

void		vector_free(t_vector *vector);
void		vector_free_deep(t_vector *vector, void (*f)(void*));
void		*vector_get(t_vector *vector, size_t idx);
t_vector	vector_on_stack(void);
t_vector	*vector_on_heap(void);
void		*vector_pop_back(t_vector *vector);
void		vector_push_back(t_vector *vector, void *item);
void		vector_resize(t_vector *vector, size_t new_size);
void		vector_reverse(t_vector *vector);
void		vector_set(t_vector *vector, size_t idx, void *item);
void		vector_sort(t_vector *vector, int (*cmp)(const void*, const void*));

#endif
