/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:56:33 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 17:30:28 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void	minimap_update(t_data *data)
{
	t_vec2	move_amount;
	t_vec2	wanted_position;
	double	offset_constant;
	t_vec2	map_center;

	if (data->inputs.toggle_minimap_target_player)
	{
		offset_constant = PLAYER_SIZE / 2 - data->minimap.range;
		wanted_position.x = data->player.pos.x + offset_constant;
		wanted_position.y = data->player.pos.y + offset_constant;
	}
	else
	{
		map_center.x = data->map.width / 2;
		map_center.y = data->map.height / 2;
		wanted_position = vec_subtract_n(map_center, data->minimap.range);
	}
	move_amount = vec_subtract(wanted_position, data->minimap.camera_pos);
	vec_multiply_n_to(&move_amount, \
		MINIMAP_CAMERA_FOLLOW_SPEED * g_mlx->delta_time);
	vec_add_to(&data->minimap.camera_pos, &move_amount);
}
