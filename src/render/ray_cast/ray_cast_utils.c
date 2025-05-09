/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:55:38 by joklein           #+#    #+#             */
/*   Updated: 2025/05/09 11:39:18 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	calc_next_dis_y(t_data *data, int32_t rn, double *next_dis,
		t_vec2_int *ray_next_tile)
{
	int			next_tile;
	t_help_ray	help_ray;

	help_ray.angle = data->ray[rn].angle.y;
	help_ray.dis_pos = data->ray[rn].dis_pos.y;
	help_ray.ray_next_tile = ray_next_tile->y;
	if (help_ray.angle >= 0)
	{
		next_tile = help_ray.ray_next_tile + 1;
		if (help_ray.angle == 0)
			help_ray.angle = 1e-6;
		*next_dis = (next_tile - help_ray.dis_pos) / help_ray.angle;
	}
	else
	{
		next_tile = help_ray.ray_next_tile;
		*next_dis = (help_ray.dis_pos - next_tile) / help_ray.angle;
		next_tile -= 1;
	}
	return (next_tile);
}

int	calc_next_dis_x(t_data *data, int32_t rn, double *next_dis,
		t_vec2_int *ray_next_tile)
{
	int			next_tile;
	t_help_ray	help_ray;

	help_ray.angle = data->ray[rn].angle.x;
	help_ray.dis_pos = data->ray[rn].dis_pos.x;
	help_ray.ray_next_tile = ray_next_tile->x;
	if (help_ray.angle >= 0)
	{
		next_tile = help_ray.ray_next_tile + 1;
		if (help_ray.angle == 0)
			help_ray.angle = 1e-6;
		*next_dis = (next_tile - help_ray.dis_pos) / help_ray.angle;
	}
	else
	{
		next_tile = help_ray.ray_next_tile;
		*next_dis = (help_ray.dis_pos - next_tile) / help_ray.angle;
		next_tile -= 1;
	}
	return (next_tile);
}

void	safe_door_value(t_data *data, int32_t rn)
{
	data->ray[rn].dis_pos_door = data->ray[rn].dis_pos;
	data->ray[rn].tile_touched_door = data->ray[rn].tile_touched;
	data->ray[rn].length_door = sqrt(pow(data->ray[rn].dis_pos.x
				- data->player.center.x, 2) + pow(data->ray[rn].dis_pos.y
				- data->player.center.y, 2));
}

void	player_facing_tile(t_data *data, int32_t rn)
{
	data->player.facing_tile.pos.x = (int)data->ray[rn].dis_pos.x;
	data->player.facing_tile.pos.y = (int)data->ray[rn].dis_pos.y;
	data->player.facing_tile.distance = data->ray[rn].length;
	if (data->ray[rn].tile_touched == 'W')
		data->player.facing_tile.pos.x -= 1;
	if (data->ray[rn].tile_touched == 'N')
		data->player.facing_tile.pos.y -= 1;
	if (data->ray[rn].length_door != -1)
	{
		data->player.facing_tile.pos.x = (int)data->ray[rn].dis_pos_door.x;
		data->player.facing_tile.pos.y = (int)data->ray[rn].dis_pos_door.y;
		data->player.facing_tile.distance = data->ray[rn].length_door;
		if (data->ray[rn].tile_touched_door == 'W')
			data->player.facing_tile.pos.x -= 1;
		if (data->ray[rn].tile_touched_door == 'N')
			data->player.facing_tile.pos.y -= 1;
	}
}
