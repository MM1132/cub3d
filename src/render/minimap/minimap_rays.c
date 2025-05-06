/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:53:36 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 16:29:22 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "settings.h"
#include "vector.h"
#include <math.h>

void	render_minimap_rays(t_data *data)
{
	t_vec2	player_center;
	int		ray_index;
	t_line	ray_line;

	player_center = vec_subtract(data->player.pos, data->minimap.camera_pos);
	vec_add_n_to(&player_center, PLAYER_SIZE / 2);
	vec_multiply_n_to(&player_center, data->minimap.scale);
	if (data->inputs.toggle_minimap_rotation)
		transform_vec_to_rotation(data, &player_center);
	ray_index = 0;
	while (ray_index < g_mlx->width)
	{
		ray_line.start = player_center;
		ray_line.end = vec_subtract(data->ray[ray_index].dis_pos, \
			data->minimap.camera_pos);
		vec_multiply_n_to(&ray_line.end, data->minimap.scale);
		if (data->inputs.toggle_minimap_rotation)
			transform_vec_to_rotation(data, &ray_line.end);
		put_line(data->minimap.img, ray_line.start, ray_line.end, 0xff33eeFF);
		ray_index++;
	}
}
