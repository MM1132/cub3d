/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:13:10 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 15:47:39 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "settings.h"

static void	minimap_render_grid_vertical(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;

	start.x = (1 - offset.x) * MINIMAP_SCALE;
	start.y = -offset.y * MINIMAP_SCALE;
	end.x = start.x;
	end.y = (data->map.height - offset.y) * MINIMAP_SCALE;
	while (start.x < (int)(data->map.width - offset.x) * MINIMAP_SCALE)
	{
		put_line(data->minimap_img, start, end, 0xFF2BEEFF);
		start.x += MINIMAP_SCALE;
		end.x = start.x;
	}
}

static void	minimap_render_grid_horizontal(t_data *data, t_vec2 offset)
{
	t_vec2	start;
	t_vec2	end;

	start.y = (1 - offset.y) * MINIMAP_SCALE;
	start.x = -offset.x * MINIMAP_SCALE;
	end.y = start.y;
	end.x = (data->map.width - offset.x) * MINIMAP_SCALE;
	while (start.y < (int)(data->map.height - offset.y) * MINIMAP_SCALE)
	{
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

