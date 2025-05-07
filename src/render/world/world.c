/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:32:26 by joklein           #+#    #+#             */
/*   Updated: 2025/05/07 16:03:02 by joklein          ###   ########.fr       */
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
	double		wall_hit;

	wall_hit = data->ray[i].dis_pos.x;
	if (data->ray[i].tile_touched == 'E' || data->ray[i].tile_touched == 'W')
		wall_hit = data->ray[i].dis_pos.y;
	if (data->ray[i].dis_pos_door.x != 0)
		wall_hit = data->ray[i].dis_pos_door.x;
	if (data->ray[i].dis_pos_door.x != 0
		&& data->ray[i].tile_touched_door == 'V')
		wall_hit = data->ray[i].dis_pos_door.y;
	wall_hit = wall_hit - (int)wall_hit;
	tex_x = (int)(wall_hit * texture->width);
	tex_y = (int)(data->txt_hei_pos);
	pixels = texture->pixels;
	bytes_per_pixel = 4;
	tex_index = (tex_y * texture->width + tex_x) * bytes_per_pixel;
	color = (pixels[tex_index] << 24) | (pixels[tex_index
			+ 1] << 16) | (pixels[tex_index + 2] << 8) | (pixels[tex_index
			+ 3]);
	mlx_put_pixel(data->img, i, u, color);
}

void	put_wall_pixel(t_data *data, int32_t i, int32_t u, t_help_ray help_ray)
{
	int	wall_start;

	wall_start = (g_mlx->height / 2) - ((int)help_ray.height / 2);
	if (data->ray[i].tile_touched == 'N')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / help_ray.height)
			* data->texture.north->height;
		put_texture_pixel(data, i, u, data->texture.north);
	}
	if (data->ray[i].tile_touched == 'E')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / help_ray.height)
			* data->texture.east->height;
		put_texture_pixel(data, i, u, data->texture.east);
	}
	if (data->ray[i].tile_touched == 'S')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / help_ray.height)
			* data->texture.south->height;
		put_texture_pixel(data, i, u, data->texture.south);
	}
	if (data->ray[i].tile_touched == 'W')
	{
		data->txt_hei_pos = ((double)(u - wall_start) / help_ray.height)
			* data->texture.west->height;
		put_texture_pixel(data, i, u, data->texture.west);
	}
}

double	calc_door_distance(int32_t i, t_data *data, t_help_ray help_ray)
{
	double	angle;
	double	distance;

	angle = atan2(data->ray[i].angle.y, data->ray[i].angle.x);
	angle = angle - help_ray.angle;
	distance = data->ray[i].length_door * cos(angle);
	if (distance < 0.00001)
		distance = 0.00001;
	return (distance);
}

void	put_door_pixel(t_data *data, int32_t i, int32_t u, t_help_ray help_ray)
{
	int		wall_start;
	double	height;

	height = g_mlx->height / calc_door_distance(i, data, help_ray);
	wall_start = (g_mlx->height / 2) - ((int)height / 2);
	data->txt_hei_pos = ((double)(u - wall_start) / height)
		* data->texture.door->height;
	put_texture_pixel(data, i, u, data->texture.door);
}

double	calc_distance(int32_t i, t_data *data, 	t_help_ray help_ray)
{
	double	angle;
	double	distance;

	angle = atan2(data->ray[i].angle.y, data->ray[i].angle.x);
	angle = angle - help_ray.angle;
	distance = data->ray[i].length * cos(angle);
	if (distance < 0.00001)
		distance = 0.00001;
	return (distance);
}

void	render_world(t_data *data)
{
	int32_t	i;
	int32_t	u;
	t_help_ray help_ray;

	i = 0;
	help_ray.angle = atan2(data->player.dir.y, data->player.dir.x);
	while (i < g_mlx->width)
	{
		u = 0;
		if (data->ray[i].dis_pos_door.x == 0)
			help_ray.height = g_mlx->height / calc_distance(i, data, help_ray);
		if (data->ray[i].dis_pos_door.x != 0)
			help_ray.height = g_mlx->height / calc_door_distance(i, data, help_ray);
		while (u < g_mlx->height)
		{
			if (u < ((g_mlx->height / 2) - ((int)help_ray.height / 2)))
				mlx_put_pixel(data->img, i, u, data->ceiling_color);
			else if (u > ((g_mlx->height / 2) + ((int)help_ray.height / 2)))
				mlx_put_pixel(data->img, i, u, data->floor_color);
			else if (data->ray[i].dis_pos_door.x != 0)
				put_door_pixel(data, i, u, help_ray);
			else
				put_wall_pixel(data, i, u, help_ray);
			u++;
		}
		i++;
	}
}
