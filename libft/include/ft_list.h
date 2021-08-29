/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:40:50 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:40:50 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

# define EMPTY_LIST_POP_MSG "Pop from the empty list"
# define E_LIST_ERROR 1

struct s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
};

typedef struct s_node	t_node;

struct s_list
{
	t_node	*back;
	t_node	*front;
	size_t	size;
};

typedef struct s_list	t_list;

void	list_free(t_list *list);
void	list_free_deep(t_list *list, void (*f)(void *));
t_list	list_on_stack(void);
t_list	*list_on_heap(void);
void	*list_pop_back(t_list *list);
void	*list_pop_front(t_list *list);
void	list_push_back(t_list *list, void *item);
void	list_push_front(t_list *list, void *item);

#endif
