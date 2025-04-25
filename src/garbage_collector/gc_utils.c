/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:09:56 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 12:26:58 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"

size_t	gc_get_allocs_total_size(void)
{
	size_t	total_size;
	t_list	*current_element;

	total_size = 0;
	current_element = g_allocs_list;
	while (current_element)
	{
		total_size += ((t_alloc *)current_element->content)->size;
		current_element = current_element->next;
	}
	return (total_size);
}

static void	init_alloc_report(t_alloc_report *report)
{
	(*report).tracked_count = 0;
	(*report).tracked_size = 0;
	(*report).untracked_count = 0;
}

// Return the allocations report numbers for the garbage collector
static t_alloc_report	gc_get_allocs_report(void)
{
	t_alloc_report	report;
	t_list			*current_element;
	t_alloc			*current_alloc;

	init_alloc_report(&report);
	current_element = g_allocs_list;
	while (current_element)
	{
		current_alloc = (t_alloc *)current_element->content;
		if (current_alloc->size == 0)
			report.untracked_count++;
		else
		{
			report.tracked_count++;
			report.tracked_size += current_alloc->size;
		}
		current_element = current_element->next;
	}
	return (report);
}

void	gc_print_alloc_report()
{
	t_alloc_report report;

	report = gc_get_allocs_report();
	if (report.tracked_count != 0 || \
		report.untracked_count != 0 || report.tracked_size != 0)
	{
		printf(COLOR_YELLOW "### Garbage Collector Report ###\n");
		printf("Tracked allocs: %ld (%ld bytes)\n", \
			report.tracked_count, report.tracked_size);
		printf("Untracked allocs: %ld\n" COLOR_RESET, report.untracked_count);
	}
	else
	{
		printf(COLOR_GREEN "SUCCESS: Garbage collector had nothing to \
			clean up!\n" COLOR_RESET);
	}
}
