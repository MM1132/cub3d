/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:38:50 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:55:54 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void	init_minimap(t_data *data)
{
	uint32_t	minimap_img_size;

	data->minimap.camera_pos = vec_add_n(\
		data->player.pos, \
		PLAYER_SIZE / 2 - MINIMAP_RANGE \
	);
	minimap_img_size = 2 * MINIMAP_RANGE * MINIMAP_SCALE;
	data->minimap.img = mlx_new_image(mlx, minimap_img_size, minimap_img_size);
}
