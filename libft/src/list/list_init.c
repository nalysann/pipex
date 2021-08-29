/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:46:50 by nalysann          #+#    #+#             */
/*   Updated: 2021/08/25 13:46:50 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_list.h"
#include "ft_stdlib.h"

t_list	list_on_stack(void)
{
	t_list	list;

	list.front = NULL;
	list.back = NULL;
	list.size = 0;
	return (list);
}

t_list	*list_on_heap(void)
{
	t_list	*list;

	list = (t_list *)xmalloc(sizeof(t_list));
	list->front = NULL;
	list->back = NULL;
	list->size = 0;
	return (list);
}
