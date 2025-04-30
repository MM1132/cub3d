/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:13:10 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 20:27:15 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "settings.h"
#include <math.h>

static void	minimap_render_grid_vertical(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;
	double	last_x;

	start.x = fmax((1 - offset.x) * MINIMAP_SCALE, \
		(1 + (int)offset.x - offset.x) * MINIMAP_SCALE);
	last_x = fmin((int)(data->map.width - offset.x) * MINIMAP_SCALE, \
		((2 * MINIMAP_RANGE)) * MINIMAP_SCALE);
	start.y = -offset.y * MINIMAP_SCALE;
	end.x = start.x;
	end.y = (data->map.height - offset.y) * MINIMAP_SCALE;
	while (start.x < last_x)
	{
		if (data->inputs.toggle_minimap_rotation)
			put_line_rotation( \
				data->minimap_img, \
				&(t_line){ start, end }, \
				(t_transform) {{ data->minimap_img->width / 2, data->minimap_img->width / 2 }, PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x)}, \
				0xFF2BEEFF \
			);
		else
			put_line(data->minimap_img, start, end, 0xFF2BEEFF);
		start.x += MINIMAP_SCALE;
		end.x = start.x;
	}
}

static void	minimap_render_grid_horizontal(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;
	double	last_y;

	start.y = fmax((1 - offset.y) * MINIMAP_SCALE, \
		(1 + (int)offset.y - offset.y) * MINIMAP_SCALE);
	last_y = fmin((int)(data->map.height - offset.y) * MINIMAP_SCALE, \
		((2 * MINIMAP_RANGE)) * MINIMAP_SCALE);
	start.x = -offset.x * MINIMAP_SCALE;
	end.y = start.y;
	end.x = (data->map.width - offset.x) * MINIMAP_SCALE;
	while (start.y < last_y)
	{
		if (data->inputs.toggle_minimap_rotation)
			put_line_rotation( \
				data->minimap_img, \
				&(t_line){ start, end }, \
				(t_transform) {{ data->minimap_img->width / 2, data->minimap_img->width / 2 }, PI * 1.5 -atan2(data->player.dir.y, data->player.dir.x)}, \
				0xFF2BEEFF \
			);
		else
			put_line(data->minimap_img, start, end, 0xFF2BEEFF);
		start.y += MINIMAP_SCALE;
		end.y = start.y;
	}
}

void	minimap_render_grid(t_data *data, t_vec2 offset)
{
	minimap_render_grid_vertical(data, offset);
	minimap_render_grid_horizontal(data, offset);
}
