/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:38:50 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 12:17:04 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include <math.h>

void	minimap_set_range(t_data *data, int32_t new_range)
{
	if (new_range < 5)
		new_range = 5;
	else if (new_range > 50)
		new_range = 50;
	data->minimap.range = new_range;
	data->minimap.size = (MAX_MINIMAP_SIZE / data->minimap.range / 2) * \
		data->minimap.range * 2;
	data->minimap.scale = data->minimap.size / data->minimap.range / 2;
	if (data->minimap.img)
		mlx_resize_image(data->minimap.img, data->minimap.size, \
			data->minimap.size);
	else
		data->minimap.img = mlx_new_image(g_mlx, data->minimap.size, \
			data->minimap.size);
}

void	init_minimap(t_data *data)
{
	data->minimap.img = NULL;
	minimap_set_range(data, fmax(data->map.width, data->map.height) / 2 * 1.1);
}
