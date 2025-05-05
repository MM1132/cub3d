/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:32:26 by joklein           #+#    #+#             */
/*   Updated: 2025/05/05 17:41:23 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

void put_wall_pixel(t_data *data, int32_t i, int32_t u)
{
    if(data->ray[i].tile_touched == 'N')
    {
        mlx_put_pixel(data->img, i, u, 0x8B4513);
    }
    else if(data->ray[i].tile_touched == 'E')
    {
        mlx_put_pixel(data->img, i, u, 0xFF8C00);
    }
    else if(data->ray[i].tile_touched == 'S')
    {
        mlx_put_pixel(data->img, i, u, 0xFAEBD7);
    }
    else if(data->ray[i].tile_touched == 'W')
    {
        mlx_put_pixel(data->img, i, u, 0x6B8E23);
    }
}


double	normalize_angle(double angle)
{
	if (angle < -M_PI)
		angle += 2 * M_PI;
	else if (angle > M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	calc_distance(int32_t i, t_data *data, double player_angle)
{
	double	angle;
	double	distance;

	angle = atan2(data->ray[i].angle.y, data->ray[i].angle.x);
	angle = normalize_angle(angle - player_angle);
	distance = data->ray[i].length * cos(angle);
	if (distance < 0.00001)
		distance = 0.00001;
	return (distance);
}

void	render_world(t_data *data)
{
	int32_t	i;
	int32_t	u;
	double	height;
	double	player_angle;

	i = 0;
	player_angle = atan2(data->player.dir.y, data->player.dir.x);
	while (i < mlx->width)
	{
		u = 0;
		height = mlx->height / calc_distance(i, data, player_angle);
		while (u < mlx->height)
		{
			if (u < ((mlx->height / 2) - ((int)height / 2)))
				mlx_put_pixel(data->img, i, u, data->ceiling_color);
			else if (u > ((mlx->height / 2) + ((int)height / 2)))
				mlx_put_pixel(data->img, i, u, data->floor_color);
			else
				put_wall_pixel(data, i, u);
			u++;
		}
		i++;
	}
}
