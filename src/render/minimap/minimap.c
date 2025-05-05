/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:56:17 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"
#include <math.h>
#include "rect.h"
#include "collision_detection.h"

static void	render_tile_with_offset(t_data *data, size_t x, size_t y, t_vec2 offset)
{
	t_rect		tile_rect;
	uint32_t	color;

	tile_rect = rect_from_point( \
		vec_new( \
			((double)x - (offset.x)) * MINIMAP_SCALE, \
			((double)y - (offset.y)) * MINIMAP_SCALE), \
		MINIMAP_SCALE, MINIMAP_SCALE);
	color = 0;
	if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
		color = 0xdbdbdbFF;
	else if (data->map.tiles[y][x].tile_type == TILE_WALL)
		color = 0x555555FF;
	if (color == 0)
		return ;
	if (data->inputs.toggle_minimap_rotation)
		put_fill_rect_transform( \
			data->minimap.img, \
			&tile_rect, \
			(t_transform) {{ data->minimap.img->width / 2, \
				data->minimap.img->height / 2 }, M_PI * 1.5 - \
				atan2(data->player.dir.y, data->player.dir.x)}, color);
	else
		put_fill_rect(data->minimap.img, &tile_rect, color);
}

void	render_minimap_tiles(t_data *data)
{
	int	x;
	int	y;

	y = (int)data->minimap.camera_pos.y - 1;
	while (++y < data->minimap.camera_pos.y + MINIMAP_RANGE * 2)
	{
		x = (int)data->minimap.camera_pos.x - 1;
		while (++x < data->minimap.camera_pos.x + MINIMAP_RANGE * 2)
		{
			if (within_map_bounds(&data->map, x, y))
				render_tile_with_offset(data, x, y, data->minimap.camera_pos);
		}
	}
}

void	minimap_render(t_data *data)
{
	put_fill(data->minimap.img, 0x222222AA);
	render_minimap_tiles(data);
	if (data->inputs.toggle_minimap_grid)
		minimap_render_grid(data);
	if (data->inputs.toggle_minimap_rays)
		render_minimap_rays(data);
	render_minimap_player(data);
	render_minimap_border(data);
}
