/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:47:02 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:47:02 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_stdio.h"

void	*list_pop_front(t_list *list)
{
	t_node	*node;
	void	*data;

	if (list->size == 0)
		ft_error(EMPTY_LIST_POP_MSG, E_LIST_ERROR);
	if (list->back == list->front)
		list->back = NULL;
	else if (list->back->prev == list->front)
		list->back->prev = NULL;
	node = list->front;
	list->front = node->next;
	if (list->front != NULL)
		list->front->prev = NULL;
	--list->size;
	data = node->data;
	free(node);
	return (data);
}
