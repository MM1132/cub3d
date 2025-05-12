/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:43 by joklein           #+#    #+#             */
/*   Updated: 2025/05/12 12:29:48 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include <math.h>

static void	calc_next_end_pos(t_data *data, int32_t rn, double next_dis,
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

static void	ray_dis_calc(t_data *data, int32_t rn, t_vec2_int *ray_next_tile)
{
	t_vec2_int	next_tile;
	t_vec2		next_dis;

	next_tile.x = calc_next_dis_x(data, rn, &next_dis.x, ray_next_tile);
	next_tile.y = calc_next_dis_y(data, rn, &next_dis.y, ray_next_tile);
	if (fabs(next_dis.x) <= fabs(next_dis.y))
	{
		data->ray[rn].tile_touched = 'E';
		if (data->ray[rn].angle.x < 0)
			data->ray[rn].tile_touched = 'W';
		ray_next_tile->x = next_tile.x;
		calc_next_end_pos(data, rn, next_dis.x, data->ray[rn].angle.x);
	}
	else
	{
		data->ray[rn].tile_touched = 'S';
		if (data->ray[rn].angle.y < 0)
			data->ray[rn].tile_touched = 'N';
		ray_next_tile->y = next_tile.y;
		calc_next_end_pos(data, rn, next_dis.y, data->ray[rn].angle.y);
	}
}

static void	calculate_ray(t_data *data, int32_t rn)
{
	int			hit;
	t_vec2_int	ray_nt;

	hit = 0;
	ray_nt.x = (int)data->player.center.x;
	ray_nt.y = (int)data->player.center.y;
	data->ray[rn].dis_pos = data->player.center;
	while (hit == 0)
	{
		ray_dis_calc(data, rn, &ray_nt);
		if (!within_map_bounds(&data->map, ray_nt.x, ray_nt.y))
			break ;
		if (data->map.tiles[ray_nt.y][ray_nt.x].tile_type == TILE_DOOR
			&& data->ray[rn].length_door == -1)
		{
			safe_door_value(data, rn);
			if (data->map.tiles[ray_nt.y][ray_nt.x].state == 1)
				hit = 1;
		}
		if (data->map.tiles[ray_nt.y][ray_nt.x].tile_type == TILE_WALL)
			hit = 1;
	}
	data->ray[rn].length = sqrt(pow(data->ray[rn].dis_pos.x
				- data->player.center.x, 2) + pow(data->ray[rn].dis_pos.y
				- data->player.center.y, 2));
}

static void	angle_calculation(t_data *data, int32_t rn)
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
		data->ray[rn].length_door = -1;
		angle_calculation(data, rn);
		calculate_ray(data, rn);
		if (rn == g_mlx->width / 2)
			player_facing_tile(data, rn);
		rn++;
	}
}
