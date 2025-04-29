/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 12:10:14 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void init_data(t_data *data)
{
	uint32_t	minimap_img_size;

	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	init_player(&data->player);
	init_inputs(&data->inputs);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	minimap_img_size = 2 * MINIMAP_RANGE * MINIMAP_SCALE;
	data->minimap_img = mlx_new_image(mlx, minimap_img_size, minimap_img_size);
}
