/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:56:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 18:32:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	within_map_bounds(t_map *map, size_t x, size_t y)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height);
}
