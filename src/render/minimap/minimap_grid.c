/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:13:10 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 16:28:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "settings.h"
#include <math.h>

static void	put_grid_line(t_data *data, t_vec2 start, t_vec2 end)
{
	put_line_rotation(\
		data->minimap.img, \
		&(t_line){start, end}, \
		(t_transform){{data->minimap.img->width / 2, \
			data->minimap.img->width / 2}, \
			M_PI * 1.5 - atan2(data->player.dir.y, \
				data->player.dir.x)}, \
		0xFF2BEEFF \
	);
}

static void	minimap_render_grid_vertical(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;
	double	last_x;

	start.x = fmax((1 - offset.x) * data->minimap.scale, \
		(1 + (int)offset.x - offset.x) * data->minimap.scale);
	last_x = fmin((int)(data->map.width - offset.x) * data->minimap.scale, \
		((2 * data->minimap.range)) * data->minimap.scale);
	start.y = -offset.y * data->minimap.scale;
	end.x = start.x;
	end.y = (data->map.height - offset.y) * data->minimap.scale;
	while (start.x < last_x)
	{
		if (data->inputs.toggle_minimap_rotation)
			put_grid_line(data, start, end);
		else
			put_line(data->minimap.img, start, end, 0xFF2BEEFF);
		start.x += data->minimap.scale;
		end.x = start.x;
	}
}

static void	minimap_render_grid_horizontal(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;
	double	last_y;

	start.y = fmax((1 - offset.y) * data->minimap.scale, \
		(1 + (int)offset.y - offset.y) * data->minimap.scale);
	last_y = fmin((int)(data->map.height - offset.y) * data->minimap.scale, \
		((2 * data->minimap.range)) * data->minimap.scale);
	start.x = -offset.x * data->minimap.scale;
	end.y = start.y;
	end.x = (data->map.width - offset.x) * data->minimap.scale;
	while (start.y < last_y)
	{
		if (data->inputs.toggle_minimap_rotation)
			put_grid_line(data, start, end);
		else
			put_line(data->minimap.img, start, end, 0xFF2BEEFF);
		start.y += data->minimap.scale;
		end.y = start.y;
	}
}

void	minimap_render_grid(t_data *data)
{
	minimap_render_grid_vertical(data, data->minimap.camera_pos);
	minimap_render_grid_horizontal(data, data->minimap.camera_pos);
}
