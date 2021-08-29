/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:47:06 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:47:06 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_list.h"
#include "ft_stdlib.h"

void	list_push_back(t_list *list, void *item)
{
	t_node	*node;

	node = (t_node *)xmalloc(sizeof(t_node));
	node->data = item;
	node->prev = list->back;
	node->next = NULL;
	if (list->back != NULL)
		list->back->next = node;
	list->back = node;
	if (list->front == NULL)
		list->front = node;
	++list->size;
}
