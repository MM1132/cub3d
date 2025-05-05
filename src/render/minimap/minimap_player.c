/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 17:37:08 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "render.h"
#include "settings.h"
#include <math.h>

t_vec2	pos_to_minimap(t_vec2 pos)
{
	pos.x = pos.x * MINIMAP_SCALE + MINIMAP_MARGIN;
	pos.y = pos.y * MINIMAP_SCALE + MINIMAP_MARGIN;
	return (pos);
}

void	render_minimap_player(t_data *data)
{
	t_vec2	player_center;
	t_line	player_line;
	t_vec2	transform_rotation;

	player_center = vec_subtract(data->player.pos, data->minimap.camera_pos);
	vec_add_n_to(&player_center, PLAYER_SIZE / 2);
	vec_multiply_n_to(&player_center, MINIMAP_SCALE);

	if (data->inputs.toggle_minimap_rotation)
	{
		// Transform the origin point of the player center
		transform_rotation.x = data->minimap.img->width / 2;
		transform_rotation.y = data->minimap.img->height / 2;
		vec_subtract_to(&player_center, &transform_rotation);
		vec_rotate_to(&player_center, M_PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x));
		vec_add_to(&player_center, &transform_rotation);
	}
	put_circle(data->minimap.img, player_center, \
		PLAYER_SIZE * MINIMAP_SCALE / 2, 0xfffb00FF);

	player_line.start = player_center;
	player_line.end = vec_multiply_n(data->player.dir, MINIMAP_SCALE * PLAYER_SIZE);
	vec_add_to(&player_line.end, &player_center);

	if (data->inputs.toggle_minimap_rotation)
	{
		vec_subtract_to(&player_line.end, &player_line.start);
		vec_rotate_to(&player_line.end, M_PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x));
		vec_add_to(&player_line.end, &player_line.start);
	}
	put_line(data->minimap.img, player_line.start, player_line.end, 0x00FF00FF);
}
