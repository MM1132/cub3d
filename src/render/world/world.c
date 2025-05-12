/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:32:26 by joklein           #+#    #+#             */
/*   Updated: 2025/05/09 15:00:17 by joklein          ###   ########.fr       */
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
	uint32_t	color;
	int			tex_index;
	double		wall_hit;

	wall_hit = data->ray[i].dis_pos.x;
	if (data->ray[i].tile_touched == 'E' || data->ray[i].tile_touched == 'W')
		wall_hit = data->ray[i].dis_pos.y;
	wall_hit = wall_hit - (int)wall_hit;
	tex_x = (int)(wall_hit * texture->width);
	tex_index = (data->txt_hei_pos * texture->height + tex_x) * 4;
	color = (texture->pixels[tex_index] << 24) | (texture->pixels[tex_index
			+ 1] << 16) | (texture->pixels[tex_index
			+ 2] << 8) | (texture->pixels[tex_index + 3]);
	mlx_put_pixel(data->img, i, u, color);
}

void	put_wall_pixel(t_data *data, int32_t i, int32_t *u, t_help_ray help_ray)
{
	int				wall_start;
	mlx_texture_t	*texture;
	int				wall_bottom;
	double			txt_step;
	double			txt_pos;

	wall_bottom = (g_mlx->height / 2) + ((int)help_ray.height / 2);
	wall_start = (g_mlx->height / 2) - ((int)help_ray.height / 2);
	if (data->ray[i].tile_touched == 'N')
		texture = data->texture.north;
	if (data->ray[i].tile_touched == 'E')
		texture = data->texture.east;
	if (data->ray[i].tile_touched == 'S')
		texture = data->texture.south;
	if (data->ray[i].tile_touched == 'W')
		texture = data->texture.west;
	txt_step = (double)texture->height / help_ray.height;
	txt_pos = (*u - wall_start) * txt_step;
	while (*u < g_mlx->height && *u < wall_bottom)
	{
		data->txt_hei_pos = (int)txt_pos;
		put_texture_pixel(data, i, *u, texture);
		txt_pos += txt_step;
		(*u)++;
	}
}

double	calc_distance(int32_t i, t_data *data, t_help_ray help_ray)
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
	int32_t		i;
	int32_t		u;
	t_help_ray	help_ray;
	t_vec2_int	wall_top_bottom;

	i = 0;
	help_ray.angle = atan2(data->player.dir.y, data->player.dir.x);
	while (i < g_mlx->width)
	{
		u = 0;
		help_ray.height = g_mlx->height / calc_distance(i, data, help_ray);
		wall_top_bottom.x = (g_mlx->height / 2) - ((int)help_ray.height / 2);
		wall_top_bottom.y = (g_mlx->height / 2) + ((int)help_ray.height / 2);
		while (u < g_mlx->height)
		{
			if (u < wall_top_bottom.x)
				mlx_put_pixel(data->img, i, u, data->ceiling_color);
			else if (u > wall_top_bottom.y)
				mlx_put_pixel(data->img, i, u, data->floor_color);
			else
				put_wall_pixel(data, i, &u, help_ray);
			u++;
		}
		if (data->ray[i].length_door != -1)
			found_door(data, i);
		i++;
	}
}
