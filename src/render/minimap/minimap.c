/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 16:37:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"

void	render_minimap_tiles(t_data *data)
{
	size_t	x;
	size_t	y;
	t_rect	rect;

	rect.width = MINIMAP_SCALE;
	rect.height = MINIMAP_SCALE;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			rect.x = x * MINIMAP_SCALE + MINIMAP_MARGIN;
			rect.y = y * MINIMAP_SCALE + MINIMAP_MARGIN;
			if (data->map.tiles[y][x].tile_type == TILE_WALL)
				put_rect(data->img, &rect, 0xFF0000FF);
			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
				put_rect(data->img, &rect, 0x00FF00FF);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_data *data)
{
	render_minimap_tiles(data);
	render_minimap_grid(data);
	render_minimap_player(data);
}
