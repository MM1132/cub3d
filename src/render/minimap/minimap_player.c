/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 16:03:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "render.h"
#include "settings.h"

void	render_minimap_player(t_data *data)
{
	t_vec2	player_center;
	t_vec2	line_to;

	player_center = vec_new(\
		MINIMAP_RANGE * MINIMAP_SCALE, \
		MINIMAP_RANGE * MINIMAP_SCALE \
	);
	put_circle(data->minimap_img, player_center, \
		PLAYER_SIZE * MINIMAP_SCALE / 2, 0xFFFFFFFF);
	if (data->inputs.toggle_minimap_rotation)
		put_line(data->minimap_img, vec_subtract(player_center, vec_new(0, MINIMAP_SCALE * PLAYER_SIZE)), player_center, 0xFF00FFFF);
	else
	{
		line_to = vec_multiply_n(data->player.dir, MINIMAP_SCALE * PLAYER_SIZE);
		line_to = vec_add(line_to, player_center);
		put_line(data->minimap_img, player_center, line_to, 0xFF00FFFF);
	}
}
