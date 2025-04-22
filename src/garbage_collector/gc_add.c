/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:09:42 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/22 18:26:07 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"

void	gc_add(void *pointer, size_t size)
{
	t_alloc	*new_alloc;
	t_list	*new_element;

	if (!pointer)
	{
		printf(COLOR_YELLOW "WARNING: Tried to add a null pointer to allocs" \
			COLOR_RESET);
		return ;
	}
	new_alloc = malloc(sizeof(t_alloc));
	if (!new_alloc)
		(free(pointer), unplanned_exit());
	new_alloc->pointer = pointer;
	new_alloc->size = size;
	new_element = ft_lstnew(new_alloc);
	if (!new_element)
	{
		free(pointer);
		free(new_alloc);
		unplanned_exit();
	}
	if (g_allocs_list == NULL)
		g_allocs_list = new_element;
	else
		ft_lstadd_front(&g_allocs_list, new_element);
}
