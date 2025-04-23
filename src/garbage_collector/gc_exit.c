/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/22 18:24:21 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"

void	unplanned_exit(void)
{
	printf(COLOR_RED "WARNING: Malloc failed, clearing up!\n" COLOR_RESET);
	gc_free_all();
	exit(EXIT_FAILURE);
}
