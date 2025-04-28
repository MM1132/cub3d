/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 19:31:38 by rreimann         ###   ########.fr       */
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

	rect.width = MINIMAP_TILE_SIZE;
	rect.height = MINIMAP_TILE_SIZE;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			rect.x = x * MINIMAP_TILE_SIZE + MINIMAP_MARGIN;
			rect.y = y * MINIMAP_TILE_SIZE + MINIMAP_MARGIN;
			if (data->map.tiles[y][x].tile_type == TILE_WALL)
				put_rect(data->img, &rect, 0xFF0000FF);
			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
				put_rect(data->img, &rect, 0x00FF00FF);
			x++;
		}
		y++;
	}
}

void	render_minimap_player(t_data *data)
{
	t_rect	rect;
	t_vec2	line_end;

	rect.x = (data->player.pos.x * MINIMAP_TILE_SIZE) - \
		MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.y = (data->player.pos.y * MINIMAP_TILE_SIZE) - \
		MINIMAP_PLAYER_SIZE / 2 + MINIMAP_MARGIN;
	rect.height = MINIMAP_PLAYER_SIZE;
	rect.width = MINIMAP_PLAYER_SIZE;
	put_rect(data->img, &rect, 0xFFFFFFFF);

	// player viewing direction line
	rect.x += MINIMAP_PLAYER_SIZE / 2;
	rect.y += MINIMAP_PLAYER_SIZE / 2;

	line_end = vec_add(\
		vec_new(rect.x, rect.y), \
		vec_multiply_n(data->player.dir, 20) \
	);
	put_line(data->img, vec_new(rect.x, rect.y), line_end, 0x0000FFFF);
}

void	render_minimap(t_data *data)
{
	render_minimap_tiles(data);
	render_minimap_player(data);
}
