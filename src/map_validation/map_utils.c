/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:56:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/20 16:23:09 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	within_map_bounds(t_map *map, size_t x, size_t y)
{
	return (x < map->width && y < map->height);
}

void	fill_text(char text[3], char *line, int *i)
{
	int	u;

	u = 0;
	while (line[(*i)] && !white_space(line, (*i)) && u < 3)
		text[u++] = line[(*i)++];
}
