/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:43 by joklein           #+#    #+#             */
/*   Updated: 2025/05/06 19:57:21 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

/*
void	draw_ray_mini_map(t_data *data, int32_t	rn)
{
	t_vec2	line_to;
	t_vec2	pl_view;

	pl_view = pos_to_minimap(data->ray[rn].start_pos);
	data->ray[rn].angle.x = -data->ray[rn].angle.x;
	data->ray[rn].angle.y = -data->ray[rn].angle.y;
	line_to = vec_multiply_n(data->ray[rn].angle, data->ray[rn].length);
	line_to = pos_to_minimap(line_to);
	line_to = vec_subtract(pl_view, line_to);
	line_to.x += MINIMAP_MARGIN;
	line_to.y += MINIMAP_MARGIN;
	data->ray[rn].angle.x = -data->ray[rn].angle.x;
	data->ray[rn].angle.y = -data->ray[rn].angle.y;
	put_line(data->img, pl_view, line_to, 0xFF00FFFF);
}
*/

void calc_next_end_pos(t_data *data, int32_t rn, double next_dis, double angle)
{
	t_vec2		num;

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


void calc_next_dis(t_help_ray ray, double *next_dis , int *next_tile)
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
	t_vec2 		next_dis;
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

void	calculate_ray(t_data *data, int32_t	rn)
{
	int	hit;
	t_vec2_int ray_next_tile;

	hit = 0;
	ray_next_tile.x = (int)data->player.center.x;
	ray_next_tile.y = (int)data->player.center.y;
	data->ray[rn].dis_pos = data->player.center;
	while (hit == 0)
	{
		ray_dis_calc(data, rn, &ray_next_tile);
		if (!within_map_bounds(&data->map, ray_next_tile.x, ray_next_tile.y))
			break ;
		if (data->map.tiles[ray_next_tile.y][ray_next_tile.x].tile_type == TILE_WALL)
			hit = 1;
		if (data->map.tiles[ray_next_tile.y][ray_next_tile.x].tile_type == TILE_DOOR)
			hit = 1;
	}
	data->ray[rn].length = sqrt(pow(data->ray[rn].dis_pos.x
				- data->player.center.x, 2)
			+ pow(data->ray[rn].dis_pos.y - data->player.center.y, 2));
}

void	ray_cast(t_data *data)
{
	int32_t	rn;

	rn = 0;
	data->player.center = vec_add_n(data->player.pos, PLAYER_SIZE / 2);
	while (rn < g_mlx->width)
	{
		data->ray[rn].angle = vec_rotate(data->player.dir, -PLAYER_VIEW_ANGLE/ 2 + rn* PLAYER_VIEW_ANGLE/ g_mlx->width);
		calculate_ray(data, rn);
		rn++;
	}
}
