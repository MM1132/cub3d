/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:09:53 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/22 18:26:07 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"

void	*gc_malloc(size_t size_bytes)
{
	void	*allocated_memory;
	t_list	*new_element;
	t_alloc	*new_alloc;

	allocated_memory = malloc(size_bytes);
	if (!allocated_memory)
		unplanned_exit();
	new_alloc = malloc(sizeof(t_alloc));
	if (!new_alloc)
		(free(allocated_memory), unplanned_exit());
	new_alloc->pointer = allocated_memory;
	new_alloc->size = size_bytes;
	new_element = ft_lstnew(new_alloc);
	if (!new_element)
	{
		free(allocated_memory);
		free(new_alloc);
		unplanned_exit();
	}
	if (g_allocs_list == NULL)
		g_allocs_list = new_element;
	else
		ft_lstadd_front(&g_allocs_list, new_element);
	return (allocated_memory);
}
