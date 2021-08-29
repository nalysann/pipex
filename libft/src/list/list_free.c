/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:46:43 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:46:43 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_list.h"

void	list_free(t_list *list)
{
	t_node	*node;
	t_node	*tmp;

	node = list->front;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	list->front = NULL;
	list->back = NULL;
	list->size = 0;
}

void	list_free_deep(t_list *list, void (*f)(void *))
{
	t_node	*node;
	t_node	*tmp;

	node = list->front;
	while (node)
	{
		tmp = node;
		node = node->next;
		f(tmp->data);
		free(tmp);
	}
	list->front = NULL;
	list->back = NULL;
	list->size = 0;
}
