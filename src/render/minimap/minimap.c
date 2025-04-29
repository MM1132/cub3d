/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:30:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 14:19:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "render.h"

//? Renders the full map
// void	render_minimap_tiles(t_data *data)
// {
// 	size_t	x;
// 	size_t	y;
// 	t_rect	rect;

// 	rect.width = MINIMAP_SCALE;
// 	rect.height = MINIMAP_SCALE;
// 	y = 0;
// 	while (y < data->map.height)
// 	{
// 		x = 0;
// 		while (x < data->map.width)
// 		{
// 			rect.x = x * MINIMAP_SCALE + MINIMAP_MARGIN;
// 			rect.y = y * MINIMAP_SCALE + MINIMAP_MARGIN;
// 			if (data->map.tiles[y][x].tile_type == TILE_WALL)
// 				put_fill_rect(data->img, &rect, 0xFF0000FF);
// 			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
// 				put_fill_rect(data->img, &rect, 0x00FF00FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	render_minimap_tiles(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	t_rect	rect;

// 	rect.width = MINIMAP_SCALE;
// 	rect.height = MINIMAP_SCALE;
// 	y = data->player.pos.y - MINIMAP_RANGE;
// 	while (y < data->player.pos.y + MINIMAP_RANGE)
// 	{
// 		x = data->player.pos.x - MINIMAP_RANGE;
// 		while (x < data->player.pos.x + MINIMAP_RANGE)
// 		{
// 			if (!coordinate_within_map(&data->map, x, y))
// 			{
// 				x++;
// 				continue ;
// 			}
// 			rect.x = x * MINIMAP_SCALE + MINIMAP_MARGIN;
// 			rect.y = y * MINIMAP_SCALE + MINIMAP_MARGIN;
// 			if (data->map.tiles[y][x].tile_type == TILE_WALL)
// 				put_fill_rect(data->img, &rect, 0xFF0000FF);
// 			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
// 				put_fill_rect(data->img, &rect, 0x00FF00FF);
// 			x++;
// 		}
// 		y++;
// 	}
// }

static int	within_bounds(t_map *map, size_t x, size_t y)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height);
}

void	render_minimap_tiles(t_data *data)
{
	int		x;
	int		y;
	t_vec2	start;
	t_rect	tile_rect;

	start.x = data->player.pos.x + PLAYER_SIZE / 2 - (double)MINIMAP_RANGE;
	start.y = data->player.pos.y + PLAYER_SIZE / 2 - (double)MINIMAP_RANGE;
	y = (int)start.y - 1;
	while (y++ < data->player.pos.y + PLAYER_SIZE / 2 + MINIMAP_RANGE)
	{
		x = (int)start.x - 1;
		while (x++ < data->player.pos.x + PLAYER_SIZE / 2 + MINIMAP_RANGE)
		{
			tile_rect.x = ((double)x - (start.x)) * MINIMAP_SCALE;
			tile_rect.y = ((double)y - (start.y)) * MINIMAP_SCALE;
			tile_rect.width = MINIMAP_SCALE;
			tile_rect.height = tile_rect.width;
			if (!within_bounds(&data->map, x, y))
				continue ;
			if (data->map.tiles[y][x].tile_type == TILE_FLOOR)
				put_fill_rect(data->minimap_img, &tile_rect, 0x00FF00FF);
			if (data->map.tiles[y][x].tile_type == TILE_WALL)
				put_fill_rect(data->minimap_img, &tile_rect, 0x555555FF);
		}
	}
}

void	render_minimap_border(t_data *data)
{
	t_rect	border_rect;

	border_rect.height = 2 * MINIMAP_RANGE * MINIMAP_SCALE;
	border_rect.width = border_rect.height;
	border_rect.x = 0;
	border_rect.y = 0;
	put_rect(data->minimap_img, &border_rect, 0xFFFFFFFF);
}

void	render_minimap(t_data *data)
{
	put_fill(data->minimap_img, 0x222222AA);
	render_minimap_tiles(data);
	render_minimap_border(data);
	render_minimap_player(data);
}
