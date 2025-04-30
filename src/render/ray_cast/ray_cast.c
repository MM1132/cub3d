/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:43 by joklein           #+#    #+#             */
/*   Updated: 2025/04/30 22:15:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

// void	calculate_wall_height(void)
// {
// }

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

void	ray_dis_calc(t_data *data, int32_t rn)
{
	t_vec2	next_tile;
	t_vec2	num;

	(void)num;
	if (data->ray[rn].angle.x >= 0)
	{
		next_tile.x = data->ray[rn].next_tile.x + 1;
		if (data->ray[rn].angle.x == 0)
			data->ray[rn].angle.x = 1e-6;
		data->ray[rn].next_dis.x = (next_tile.x - data->ray[rn].last_dis_pos.x)
			/ data->ray[rn].angle.x;
	}
	else
	{
		next_tile.x = data->ray[rn].next_tile.x;
		data->ray[rn].next_dis.x = (data->ray[rn].last_dis_pos.x - next_tile.x)
			/ data->ray[rn].angle.x;
		next_tile.x -= 1;
	}
	if (data->ray[rn].angle.y >= 0)
	{
		next_tile.y = data->ray[rn].next_tile.y + 1;
		if (data->ray[rn].angle.y == 0)
			data->ray[rn].angle.y = 1e-6;
		data->ray[rn].next_dis.y = (next_tile.y - data->ray[rn].last_dis_pos.y)
			/ data->ray[rn].angle.y;
	}
	else
	{
		next_tile.y = data->ray[rn].next_tile.y;
		data->ray[rn].next_dis.y = (data->ray[rn].last_dis_pos.y - next_tile.y)
			/ data->ray[rn].angle.y;
		next_tile.y -= 1;
	}
	if (fabs(data->ray[rn].next_dis.x) <= fabs(data->ray[rn].next_dis.y))
	{
		data->ray[rn].next_tile.x = next_tile.x;
		num.x = data->ray[rn].next_dis.x * data->ray[rn].angle.x;
		num.y = data->ray[rn].next_dis.x * data->ray[rn].angle.y;
		if (data->ray[rn].next_dis.x < 0 && data->ray[rn].angle.x < 0)
		{
			num.x = -(data->ray[rn].next_dis.x * data->ray[rn].angle.x);
			num.y = -(data->ray[rn].next_dis.x * data->ray[rn].angle.y);
		}
		data->ray[rn].last_dis_pos.x = data->ray[rn].last_dis_pos.x + num.x;
		data->ray[rn].last_dis_pos.y = data->ray[rn].last_dis_pos.y + num.y;
	}
	else
	{
		data->ray[rn].next_tile.y = next_tile.y;
		num.x = data->ray[rn].next_dis.y * data->ray[rn].angle.x;
		num.y = data->ray[rn].next_dis.y * data->ray[rn].angle.y;
		if (data->ray[rn].next_dis.y < 0 && data->ray[rn].angle.y < 0)
		{
			num.x = -(data->ray[rn].next_dis.y * data->ray[rn].angle.x);
			num.y = -(data->ray[rn].next_dis.y * data->ray[rn].angle.y);
		}
		data->ray[rn].last_dis_pos.x = data->ray[rn].last_dis_pos.x + num.x;
		data->ray[rn].last_dis_pos.y = data->ray[rn].last_dis_pos.y + num.y;
	}
}

void	calculate_ray(t_data *data, int32_t	rn)
{
	int	hit;

	hit = 0;
	data->ray[rn].next_tile.x = (int)data->ray[rn].start_pos.x;
	data->ray[rn].next_tile.y = (int)data->ray[rn].start_pos.y;
	first_dis_calc(data, rn);
	if (data->map.tiles[(int)data->ray[rn].next_tile.y][(int)data->ray[rn].next_tile.x].tile_type != TILE_FLOOR)
		hit = 1;
	while (hit == 0)
	{
		ray_dis_calc(data, rn);
		if (data->map.tiles[(int)data->ray[rn].next_tile.y][(int)data->ray[rn].next_tile.x].tile_type != TILE_FLOOR)
			hit = 1;
	}
	data->ray[rn].length = sqrt(pow(data->ray[rn].last_dis_pos.x
				- data->ray[rn].start_pos.x, 2)
			+ pow(data->ray[rn].last_dis_pos.y - data->ray[rn].start_pos.y, 2));
}

void	ray_cast(t_data *data)
{
	int32_t	rn;

	rn = 0;
	while (rn < mlx->width)
	{
		data->ray[rn].start_pos = vec_add_value(data->player.pos, PLAYER_SIZE/ 2);
		data->ray[rn].angle = vec_rotate(data->player.dir, -PLAYER_VIEW_ANGLE/ 2 + rn* PLAYER_VIEW_ANGLE/ mlx->width);
		calculate_ray(data, rn);
		draw_ray_mini_map(data, rn);
		data->ray[rn].angle = vec_rotate(data->ray[rn].angle, PLAYER_VIEW_ANGLE/ mlx->width);
		rn++;
	}
}
