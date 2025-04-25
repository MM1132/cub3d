/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 17:40:12 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"

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
	rect.x = (data->player.pos.x * MINIMAP_TILE_SIZE) + MINIMAP_TILE_SIZE/2 - MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.y = (data->player.pos.y * MINIMAP_TILE_SIZE) + MINIMAP_TILE_SIZE/2 - MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.height = MINIMAP_PLAYER_SIZE;
	rect.width = MINIMAP_PLAYER_SIZE;
	put_rect(data->img, &rect, 0xFFFFFFFF);

    // Draw a line from player to mouse. For fun
	rect.x += MINIMAP_PLAYER_SIZE / 2;
	rect.y += MINIMAP_PLAYER_SIZE / 2;
	// printf("Player position: %f; %f\n", data->player.pos.x, data->player.pos.y);
	t_vec2	player_pos_screen = vec_new(rect.x, rect.y);
	put_line(data->img, player_pos_screen, data->inputs.mouse_pos, 0xAFFFFFFF);
}
