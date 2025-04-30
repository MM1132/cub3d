/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 22:24:12 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"
#include <math.h>
#include "rect.h"

static int	within_bounds(t_map *map, size_t x, size_t y)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height);
}

static void	render_tile_with_offset(t_data *data, int x, int y, t_vec2 offset)
{
	t_rect		tile_rect;
	uint32_t	color;

	tile_rect = rect_from_point( \
		vec_new( \
			((double)x - (offset.x)) * MINIMAP_SCALE, \
			((double)y - (offset.y)) * MINIMAP_SCALE), \
		MINIMAP_SCALE,
		MINIMAP_SCALE
	);
	if (!within_bounds(&data->map, x, y))
		return ;
	color = 0;
	if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
		color = 0x00FF00FF;
	else if (data->map.tiles[y][x].tile_type == TILE_WALL)
		color = 0x555555FF;
	if (color == 0)
		return ;
	if (data->inputs.toggle_minimap_rotation)
		put_rect_rotation( \
			data->minimap_img, \
			&tile_rect, \
			(t_transform) {{ data->minimap_img->width / 2, data->minimap_img->width / 2 }, PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x)}, \
			color \
		);
	else
		put_fill_rect(data->minimap_img, &tile_rect, color);
}

void	render_minimap_tiles(t_data *data)
{
	int		x;
	int		y;
	t_vec2	start;

	// The coordinates of the top-most tile we can see
	start.x = data->player.pos.x + PLAYER_SIZE / 2 - (double)MINIMAP_RANGE;
	start.y = data->player.pos.y + PLAYER_SIZE / 2 - (double)MINIMAP_RANGE;
	y = (int)start.y - 1;
	while (y++ < data->player.pos.y + PLAYER_SIZE / 2 + MINIMAP_RANGE)
	{
		x = (int)start.x - 1;
		while (x++ < data->player.pos.x + PLAYER_SIZE / 2 + MINIMAP_RANGE)
		{
			render_tile_with_offset(data, x, y, start);
		}
	}
	if (data->inputs.toggle_minimap_grid)
		minimap_render_grid(data, start);
}

void	render_minimap_border(t_data *data)
{
	t_rect	border_rect;

	border_rect = rect_from_point( \
		vec_new(0, 0), \
		2 * MINIMAP_RANGE * MINIMAP_SCALE, \
		2 * MINIMAP_RANGE * MINIMAP_SCALE
	);
	put_rect(data->minimap_img, &border_rect, 0xFFFFFFFF);
}

void	render_minimap(t_data *data)
{
	put_fill(data->minimap_img, 0x222222AA);
	render_minimap_tiles(data);
	render_minimap_border(data);
	render_minimap_player(data);
}
