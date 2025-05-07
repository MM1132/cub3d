/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeros_enclosed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:29:35 by joklein           #+#    #+#             */
/*   Updated: 2025/05/07 12:24:00 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_function(size_t x, size_t y, t_data *data)
{
	t_tile_type	type;

	type = data->map.tiles[y][x].tile_type;
	if (type == TILE_FLOOR || type == TILE_WALL)
		return (0);
	return (1);
}

static int	check_surround_pos(size_t x, size_t y, t_data *data)
{
	if (y == 0)
		return (1);
	else if (check_function(x, y - 1, data))
		return (1);
	if (y == data->map.height - 1)
		return (1);
	else if (check_function(x, y + 1, data))
		return (1);
	if (x == 0)
		return (1);
	else if (check_function(x - 1, y, data))
		return (1);
	if (x == data->map.width - 1)
		return (1);
	else if (check_function(x + 1, y, data))
		return (1);
	return (0);
}

int	zeros_enclosed(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.tiles[y][x].tile_type != TILE_WALL &&  data->map.tiles[y][x].tile_type != TILE_SPACE
				&& check_surround_pos(x, y, data))
				return (err_mssg());
			x++;
		}
		y++;
	}
	return (0);
}
