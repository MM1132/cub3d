/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 16:47:40 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "render.h"
#include "settings.h"

static t_vec2	pos_to_minimap(t_vec2 pos)
{
	pos.x = pos.x * MINIMAP_SCALE + MINIMAP_MARGIN;
	pos.y = pos.y * MINIMAP_SCALE + MINIMAP_MARGIN;
	return (pos);
}

void	render_minimap_player(t_data *data)
{
	t_vec2	player_center;
	t_vec2	line_to;

	player_center = pos_to_minimap(vec_new(
		data->player.pos.x + PLAYER_SIZE / 2,
		data->player.pos.y + PLAYER_SIZE / 2
	));
	put_circle(data->img, player_center, PLAYER_SIZE * MINIMAP_SCALE / 2, \
		0xFFFFFFFF);
	line_to = vec_multiply_n(data->player.dir, MINIMAP_SCALE * PLAYER_SIZE);
	line_to = vec_add(line_to, player_center);
	put_line(data->img, player_center, line_to, 0xFF00FFFF);
}
