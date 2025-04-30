/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:20:34 by joklein           #+#    #+#             */
/*   Updated: 2025/04/30 15:59:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

void	first_dis_calc(t_data *data, int32_t	rn)
{
	t_vec2	next_tile;
	t_vec2	num;

	if (data->ray[rn].angle.x >= 0)
	{
		next_tile.x = (int)data->ray[rn].start_pos.x + 1;
		if (data->ray[rn].angle.x == 0)
			data->ray[rn].angle.x = 1e-6;
		data->ray[rn].next_dis.x = (next_tile.x - data->ray[rn].start_pos.x) / data->ray[rn].angle.x;
	}
	else
	{
		next_tile.x = (int)data->ray[rn].start_pos.x;
		data->ray[rn].next_dis.x = (data->ray[rn].start_pos.x - next_tile.x) / data->ray[rn].angle.x;
		next_tile.x -= 1;
	}
	if (data->ray[rn].angle.y >= 0)
	{
		next_tile.y = (int)data->ray[rn].start_pos.y + 1;
		if (data->ray[rn].angle.y == 0)
			data->ray[rn].angle.y = 1e-6;
		data->ray[rn].next_dis.y = (next_tile.y - data->ray[rn].start_pos.y) / data->ray[rn].angle.y;
	}
	else
	{
		next_tile.y = (int)data->ray[rn].start_pos.y;
		data->ray[rn].next_dis.y = (data->ray[rn].start_pos.y - next_tile.y) / data->ray[rn].angle.y;
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
		data->ray[rn].last_dis_pos.x = data->ray[rn].start_pos.x + num.x;
		data->ray[rn].last_dis_pos.y = data->ray[rn].start_pos.y + num.y;
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
		data->ray[rn].last_dis_pos.x = data->ray[rn].start_pos.x + num.x;
		data->ray[rn].last_dis_pos.y = data->ray[rn].start_pos.y + num.y;
	}
}