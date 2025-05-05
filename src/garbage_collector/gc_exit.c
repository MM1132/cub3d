/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 21:10:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "colors.h"
#include "MLX42.h"
#include "cub3d.h"

void	unplanned_exit(void)
{
	printf(COLOR_RED "WARNING: Malloc failed, clearing up!\n" COLOR_RESET);
	mlx_terminate(g_mlx);
	gc_free_all();
	exit(EXIT_FAILURE);
}
