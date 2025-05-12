/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:10:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 15:38:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "libft.h"

extern t_list	*g_allocs_list;

typedef struct s_alloc
{
	void	*pointer;
	size_t	size;
}	t_alloc;

typedef struct s_alloc_report
{
	size_t	tracked_count;
	size_t	tracked_size;
	size_t	untracked_count;
}	t_alloc_report;

// Allocate memory with the size of `bytes`
// and add it to the `allocs` linked list
void			*gc_malloc(size_t size_bytes);

// Free the passed address of memmory
// also remove it from the `allocs` linked list
// if the passed address was not found from the `allocs` list
// ...print a warning message in the console (aka "double free detected")
void			gc_free(void *pointer);

// Free up all the memory in the `allocs` list
// Print a short conclusion as to how much memory was freed up
void			gc_free_all(void);

// Get the total size of all allocated elements together
size_t			gc_get_allocs_total_size(void);

// Add a previously allocated pointer to the linked list of allocs
// If the `size` is passed as 0, the size of the memory will not be tracked
// Pass any other `size`, and it will be tracked
void			gc_add(void *pointer, size_t size);

// Clear everything and exit out of the program
void			unplanned_exit(void);

// Print out the repot of allocs in our program
void			gc_print_alloc_report(void);

// SAFE FUNCTIONS
char			**safe_split(char *str, char c);
void			free_split(char **split);

#endif
