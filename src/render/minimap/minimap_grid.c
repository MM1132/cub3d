/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:13:10 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 16:36:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "settings.h"

void	render_minimap_grid(t_data *data)
{
	t_vec2	from;
	t_vec2	to;
	size_t	line_index;

	from = vec_new(MINIMAP_MARGIN, MINIMAP_MARGIN);
	to = vec_new(data->map.width * MINIMAP_SCALE + MINIMAP_MARGIN, \
		MINIMAP_MARGIN);
	line_index = 0;
	while (line_index++ <= data->map.height)
	{
		put_line(data->img, from, to, 0xFFFFFFFF);
		from.y += MINIMAP_SCALE;
		to.y += MINIMAP_SCALE;
	}
	from = vec_new(MINIMAP_MARGIN, MINIMAP_MARGIN);
	to = vec_new(MINIMAP_MARGIN, MINIMAP_MARGIN + data->map.height * \
		MINIMAP_SCALE);
	line_index = 0;
	while (line_index++ <= data->map.width)
	{
		put_line(data->img, from, to, 0xFFFFFFFF);
		from.x += MINIMAP_SCALE;
		to.x += MINIMAP_SCALE;
	}
}
