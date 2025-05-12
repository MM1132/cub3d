/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:39:45 by joklein           #+#    #+#             */
/*   Updated: 2025/05/12 15:26:05 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	put_door_pixel(t_data *data, int32_t i, int32_t *u, t_help_ray help_ray)
{
	mlx_texture_t	*texture;
	int				wall_bottom;
	double			txt_step;
	double			txt_pos;

	wall_bottom = (g_mlx->height / 2) + ((int)help_ray.height / 2);
	if (data->ray[i].length == data->ray[i].length_door)
		texture = data->texture.door_c;
	else
		texture = data->texture.door_o;
	txt_step = (double)texture->height / help_ray.height;
	txt_pos = (*u - ((int)((g_mlx->height / 2) - ((int)help_ray.height / 2))))
		* txt_step;
	data->ray[i].length_door = -2;
	while (*u < g_mlx->height && *u < wall_bottom)
	{
		data->txt_hei_pos = (int)txt_pos;
		put_texture_pixel(data, i, *u, texture);
		txt_pos += txt_step;
		(*u)++;
	}
	put_texture_pixel(data, i, *u, texture);
}

void	found_door(t_data *data, int32_t i)
{
	t_help_ray	help_ray;
	int32_t		u;

	u = 0;
	help_ray.angle = atan2(data->player.dir.y, data->player.dir.x);
	help_ray.height = g_mlx->height / calc_distance(i, data, help_ray,
			data->ray[i].length_door);
	while (u < g_mlx->height)
	{
		if (u < ((g_mlx->height / 2) - ((int)help_ray.height / 2)))
			(void)u;
		else if (u > ((g_mlx->height / 2) + ((int)help_ray.height / 2)))
			(void)u;
		else
			put_door_pixel(data, i, &u, help_ray);
		u++;
	}
}
