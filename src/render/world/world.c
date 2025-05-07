/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:32:26 by joklein           #+#    #+#             */
/*   Updated: 2025/05/07 11:42:12 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

void	put_texture_pixel(t_data *data, int32_t i, int32_t u,
		mlx_texture_t *texture)
{
	int			tex_x;
	int			tex_y;
	uint32_t	color;
	uint8_t		*pixels;
	int			bytes_per_pixel;
	int			tex_index;
	double wall_hit;

	wall_hit = data->ray[i].dis_pos.x;
	if (data->ray[i].tile_touched == 'E' || data->ray[i].tile_touched == 'W')
		wall_hit = data->ray[i].dis_pos.y;
	wall_hit = wall_hit - (int)wall_hit;
	tex_x = (int)(wall_hit * texture->width);
	tex_y = (int)(data->txt_hei_pos);
	pixels = texture->pixels;
	bytes_per_pixel = 4;
	tex_index = (tex_y * texture->width + tex_x) * bytes_per_pixel;
	color = (pixels[tex_index] << 24)
	      | (pixels[tex_index + 1] << 16)
	      | (pixels[tex_index + 2] << 8)
	      | (pixels[tex_index + 3]);
	mlx_put_pixel(data->img, i, u, color);
}

void	put_wall_pixel(t_data *data, int32_t i, int32_t u, double height)
{
	int	wall_start;

	wall_start = (g_mlx->height / 2) - ((int)height / 2);
	if (data->ray[i].tile_touched == 'N')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / height)
			* data->no_texture->height;
		put_texture_pixel(data, i, u, data->no_texture);
	}
	if (data->ray[i].tile_touched == 'E')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / height)
			* data->ea_texture->height;
		put_texture_pixel(data, i, u, data->ea_texture);
	}
	if (data->ray[i].tile_touched == 'S')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / height)
			* data->so_texture->height;
		put_texture_pixel(data, i, u, data->so_texture);
	}
	if (data->ray[i].tile_touched == 'W')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / height)
			* data->we_texture->height;
		put_texture_pixel(data, i, u, data->we_texture);
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
	distance = data->ray[i].length * cos(angle) ;
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
	while (i < g_mlx->width)
	{
		u = 0;
		height = g_mlx->height / calc_distance(i, data, player_angle);
		while (u < g_mlx->height)
		{
			if (u < ((g_mlx->height / 2) - ((int)height / 2)))
				mlx_put_pixel(data->img, i, u, data->ceiling_color);
			else if (u > ((g_mlx->height / 2) + ((int)height / 2)))
				mlx_put_pixel(data->img, i, u, data->floor_color);
			else
				put_wall_pixel(data, i, u, height);
			u++;
		}
		i++;
	}
}
