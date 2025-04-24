/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/24 16:25:41 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_data *data)
{
	size_t	x;
	size_t	y;
	t_rect	rect;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			rect.x = x * MINIMAP_TILE_SIZE + MINIMAP_MARGIN;
			rect.y = y * MINIMAP_TILE_SIZE + MINIMAP_MARGIN;
			rect.width = MINIMAP_TILE_SIZE;
			rect.height = MINIMAP_TILE_SIZE;
			if (data->map.tiles[y][x].tile_type == TILE_WALL)
				put_rect(data->img, &rect, 0xFF0000FF);
			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
				put_rect(data->img, &rect, 0x00FF00FF);
			x++;
		}
		y++;
	}
	// Render the player
	rect.x = (data->player.pos_x * MINIMAP_TILE_SIZE) + MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.y = (data->player.pos_y * MINIMAP_TILE_SIZE) + MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.height = MINIMAP_PLAYER_SIZE;
	rect.width = MINIMAP_PLAYER_SIZE;
	put_rect(data->img, &rect, 0xFFFFFFFF);
}
