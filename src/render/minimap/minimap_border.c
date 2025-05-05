/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:54:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 14:54:34 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "shape_types.h"
#include "settings.h"
#include "render.h"

void	render_minimap_border(t_data *data)
{
	t_rect	border_rect;

	border_rect = rect_from_point( \
		vec_new(0, 0), \
		2 * MINIMAP_RANGE * MINIMAP_SCALE, \
		2 * MINIMAP_RANGE * MINIMAP_SCALE
	);
	put_rect(data->minimap.img, &border_rect, 0xFFFFFFFF);
}
