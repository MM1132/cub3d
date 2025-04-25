/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:09:48 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 12:27:17 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"

static void	free_alloc(void *pointer)
{
	t_alloc	*alloc;

	alloc = (t_alloc *)pointer;
	free(alloc->pointer);
	free(alloc);
}

void	gc_free(void *pointer)
{
	t_list	*current_element;
	t_alloc	*current_alloc;

	current_element = g_allocs_list;
	while (current_element)
	{
		current_alloc = (t_alloc *)current_element->content;
		if (current_alloc->pointer == pointer)
		{
			ft_lstremoveone(&g_allocs_list, current_element, free_alloc);
			return ;
		}
		current_element = current_element->next;
	}
	printf(COLOR_RED \
"WARNING: You are trying to gc_free the same pointer twice!\n" COLOR_RESET);
}

void	gc_free_all(void)
{
	gc_print_alloc_report();
	ft_lstclear(&g_allocs_list, free_alloc);
}
