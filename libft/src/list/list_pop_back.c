/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:46:55 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:46:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_stdio.h"

void	*list_pop_back(t_list *list)
{
	t_node	*node;
	void	*data;

	if (list->size == 0)
		ft_error(EMPTY_LIST_POP_MSG, E_LIST_ERROR);
	if (list->front == list->back)
		list->front = NULL;
	else if (list->front->next == list->back)
		list->front->next = NULL;
	node = list->back;
	list->back = node->prev;
	if (list->back != NULL)
		list->back->next = NULL;
	--list->size;
	data = node->data;
	free(node);
	return (data);
}
