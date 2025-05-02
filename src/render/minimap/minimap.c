/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 02:25:44 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"
#include <math.h>
#include "rect.h"
#include "collision_detection.h"

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
		color = 0xdbdbdbFF;
	else if (data->map.tiles[y][x].tile_type == TILE_WALL)
		color = 0x555555FF;
	if (color == 0)
		return ;

	if (data->inputs.toggle_minimap_rotation)
		put_fill_rect_rotation( \
			data->minimap.img, \
			&tile_rect, \
			(t_transform) {{ data->minimap.img->width / 2, data->minimap.img->height / 2 }, PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x)}, \
			color \
		);
	else
		put_fill_rect(data->minimap.img, &tile_rect, color);
}

void	render_minimap_tiles(t_data *data)
{
	int		x;
	int		y;

	// printf("Camera pos: %f; %f\n", data->minimap.camera_pos.x,data->minimap.camera_pos.y);
	y = (int)data->minimap.camera_pos.y;
	// printf("x start: %f\n", (int)data->minimap.camera_pos.x / MINIMAP_SCALE - 1);
	while (y++ < data->minimap.camera_pos.y + MINIMAP_RANGE * 2 - 2)
	{
		x = (int)data->minimap.camera_pos.x;
		while (x++ < data->minimap.camera_pos.x + MINIMAP_RANGE * 2 - 2)
		{
			// printf("rendering tile at: %d; %d\n", x, y);
			render_tile_with_offset(data, x, y, data->minimap.camera_pos);
		}
	}
	if (data->inputs.toggle_minimap_grid)
		minimap_render_grid(data, data->minimap.camera_pos);
}

void	render_minimap_border(t_data *data)
{
	t_rect	border_rect;

	border_rect = rect_from_point( \
		vec_new(0, 0), \
		2 * MINIMAP_RANGE * MINIMAP_SCALE, \
		2 * MINIMAP_RANGE * MINIMAP_SCALE
	);
	put_rect(data->minimap.img, &border_rect, 0xFFFFFFFF);
}

void	minimap_render(t_data *data)
{
	put_fill(data->minimap.img, 0x222222AA);
	render_minimap_tiles(data);
	render_minimap_border(data);
	render_minimap_player(data);

	//! TEST the collision detection here
	t_rect static_rect = rect_new2(vec_new(100, 100), vec_new(200, 200));
	t_circle circle = { vec_subtract_n(data->inputs.mouse_pos, MINIMAP_MARGIN), 50 };

	// Change the color of the second rect based on collision
	uint32_t color = 0x005500FF;
	t_collision collision = circle_collides_rect(&circle, &static_rect);
	if (collision.colliding)
	{
		color = 0xFF0000FF;
		t_vec2 move_amount = vec_multiply_n(collision.dir, collision.amount);
		vec_subtract_to(&circle.pos, &move_amount);
	}
	
	put_fill_rect_rotation(data->minimap.img, &static_rect, (t_transform) {(t_vec2){0,0}, 0}, 0x005500FF);
	put_circle(data->minimap.img, circle.pos, circle.radius, color);
}
