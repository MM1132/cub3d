/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:43 by joklein           #+#    #+#             */
/*   Updated: 2025/05/08 12:46:45 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

void	calc_next_end_pos(t_data *data, int32_t rn, double next_dis,
		double angle)
{
	t_vec2	num;

	num.x = next_dis * data->ray[rn].angle.x;
	num.y = next_dis * data->ray[rn].angle.y;
	if (next_dis < 0 && angle < 0)
	{
		num.x = -num.x;
		num.y = -num.y;
	}
	data->ray[rn].dis_pos.x = data->ray[rn].dis_pos.x + num.x;
	data->ray[rn].dis_pos.y = data->ray[rn].dis_pos.y + num.y;
}

void	calc_next_dis(t_help_ray ray, double *next_dis, int *next_tile)
{
	if (ray.angle >= 0)
	{
		*next_tile = ray.ray_next_tile + 1;
		if (ray.angle == 0)
			ray.angle = 1e-6;
		*next_dis = (*next_tile - ray.dis_pos) / ray.angle;
	}
	else
	{
		*next_tile = ray.ray_next_tile;
		*next_dis = (ray.dis_pos - *next_tile) / ray.angle;
		*next_tile -= 1;
	}
}

void	ray_dis_calc(t_data *data, int32_t rn, t_vec2_int *ray_next_tile)
{
	t_vec2_int	next_tile;
	t_vec2		next_dis;
	t_help_ray	help_ray;
	double		angle;

	help_ray.angle = data->ray[rn].angle.x;
	help_ray.dis_pos = data->ray[rn].dis_pos.x;
	help_ray.ray_next_tile = ray_next_tile->x;
	calc_next_dis(help_ray, &next_dis.x, &next_tile.x);
	help_ray.angle = data->ray[rn].angle.y;
	help_ray.dis_pos = data->ray[rn].dis_pos.y;
	help_ray.ray_next_tile = ray_next_tile->y;
	calc_next_dis(help_ray, &next_dis.y, &next_tile.y);
	if (fabs(next_dis.x) <= fabs(next_dis.y))
	{
		data->ray[rn].tile_touched = 'E';
		if (data->ray[rn].angle.x < 0)
			data->ray[rn].tile_touched = 'W';
		ray_next_tile->x = next_tile.x;
		angle = data->ray[rn].angle.x;
		calc_next_end_pos(data, rn, next_dis.x, angle);
	}
	else
	{
		data->ray[rn].tile_touched = 'S';
		if (data->ray[rn].angle.y < 0)
			data->ray[rn].tile_touched = 'N';
		ray_next_tile->y = next_tile.y;
		angle = data->ray[rn].angle.y;
		calc_next_end_pos(data, rn, next_dis.y, angle);
	}
}

void	calculate_ray(t_data *data, int32_t rn)
{
	int			hit;
	t_vec2_int	ray_next_tile;

	hit = 0;
	ray_next_tile.x = (int)data->player.center.x;
	ray_next_tile.y = (int)data->player.center.y;
	data->ray[rn].dis_pos = data->player.center;
	while (hit == 0)
	{
		ray_dis_calc(data, rn, &ray_next_tile);
		if (!within_map_bounds(&data->map, ray_next_tile.x, ray_next_tile.y))
			break ;
		if (data->map.tiles[ray_next_tile.y][ray_next_tile.x].tile_type == TILE_DOOR
			&& data->ray[rn].dis_pos_door.x == 0)
		{
			data->ray[rn].dis_pos_door = data->ray[rn].dis_pos;
			data->ray[rn].tile_touched_door = 'H';
			if (data->ray[rn].tile_touched == 'W'
				|| data->ray[rn].tile_touched == 'E')
				data->ray[rn].tile_touched_door = 'V';
			data->ray[rn].length_door = sqrt(pow(data->ray[rn].dis_pos.x
						- data->player.center.x, 2)
					+ pow(data->ray[rn].dis_pos.y - data->player.center.y, 2));
			if(data->map.tiles[ray_next_tile.y][ray_next_tile.x].state == 1)
				hit = 1;
		}
		if (data->map.tiles[ray_next_tile.y][ray_next_tile.x].tile_type == TILE_WALL)
			hit = 1;
	}
	data->ray[rn].length = sqrt(pow(data->ray[rn].dis_pos.x
				- data->player.center.x, 2) + pow(data->ray[rn].dis_pos.y
				- data->player.center.y, 2));
}

void	angle_calculation(t_data *data, int32_t rn)
{
	t_vec2	plane_vec_calc;
	double	step_width;
	t_vec2	step_vec;
	t_vec2	norm;

	step_width = (tan(PLAYER_VIEW_ANGLE / 2) * 2) / g_mlx->width;
	norm = vec_normalize(data->player.dir);
	plane_vec_calc = vec_add(data->player.center, norm);
	norm = vec_rotate(norm, -M_PI_2);
	step_vec = vec_multiply_n(norm, ((g_mlx->width / 2) - rn) * step_width);
	plane_vec_calc = vec_add(plane_vec_calc, step_vec);
	data->ray[rn].angle = vec_subtract(plane_vec_calc, data->player.center);
}

void	ray_cast(t_data *data)
{
	int32_t	rn;

	rn = 0;
	data->player.center = vec_add_n(data->player.pos, PLAYER_SIZE / 2);
	while (rn < g_mlx->width)
	{
		data->ray[rn].dis_pos_door.x = 0;
		angle_calculation(data, rn);
		calculate_ray(data, rn);
		if (rn == g_mlx->width / 2)
		{
			data->player.facing_tile.pos.x = (int)data->ray[rn].dis_pos.x;
			data->player.facing_tile.pos.y = (int)data->ray[rn].dis_pos.y;
			data->player.facing_tile.distance = data->ray[rn].length;
			if(data->ray[rn].dis_pos_door.x != 0)
			{
				data->player.facing_tile.pos.x = (int)data->ray[rn].dis_pos_door.x;
				data->player.facing_tile.pos.y = (int)data->ray[rn].dis_pos_door.y;
				data->player.facing_tile.distance = data->ray[rn].length_door;
			}
			if (data->ray[rn].tile_touched == 'W')
				data->player.facing_tile.pos.x -= 1;
			if (data->ray[rn].tile_touched == 'N')
				data->player.facing_tile.pos.y -= 1;
			
		}
		rn++;
	}
}
