/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:39:45 by joklein           #+#    #+#             */
/*   Updated: 2025/05/09 12:22:46 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include <math.h>

void	put_texture_pixel_door(t_data *data, int32_t i, int32_t u,
		mlx_texture_t *texture)
{
	int			tex_x;
	int			tex_y;
	uint32_t	color;
	uint8_t		*pixels;
	int			bytes_per_pixel;
	int			tex_index;
	double		wall_hit;
	int			alpha;

	wall_hit = data->ray[i].dis_pos.x;
	if (data->ray[i].tile_touched == 'E' || data->ray[i].tile_touched == 'W')
		wall_hit = data->ray[i].dis_pos.y;
	if (data->ray[i].length_door != -1)
		wall_hit = data->ray[i].dis_pos_door.x;
	if (data->ray[i].length_door != -1
		&& (data->ray[i].tile_touched_door == 'E' || data->ray[i].tile_touched_door == 'W'))
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
	alpha = color & 0xFF;
	if (alpha != 0)
		mlx_put_pixel(data->img, i, u, color);
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
	int	wall_start;

	wall_start = (g_mlx->height / 2) - ((int)help_ray.height / 2);
	data->txt_hei_pos = ((double)(u - wall_start) / help_ray.height)
		* data->texture.door_c->height;
	if (data->ray[i].tile_touched && data->ray[i].length == data->ray[i].length_door)
		put_texture_pixel_door(data, i, u, data->texture.door_c);
	else
		put_texture_pixel_door(data, i, u, data->texture.door_o);
}

void	found_door(t_data *data, int32_t i)
{
	t_help_ray	help_ray;
	int32_t		u;

	u = 0;
	help_ray.angle = atan2(data->player.dir.y, data->player.dir.x);
	help_ray.height = g_mlx->height / calc_door_distance(i, data, help_ray);
	while (u < g_mlx->height)
	{
		if (u < ((g_mlx->height / 2) - ((int)help_ray.height / 2)))
			(void)u;
		else if (u > ((g_mlx->height / 2) + ((int)help_ray.height / 2)))
			(void)u;
		else
			put_door_pixel(data, i, u, help_ray);
		u++;
	}
}
