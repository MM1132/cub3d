/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 15:12:40 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

void	init_data(t_data *data)
{
	uint32_t	minimap_img_size;

	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->map.tiles = NULL;
	data->ray = NULL;
	init_player(&data->player);
	init_inputs(&data->inputs);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	minimap_img_size = 2 * MINIMAP_RANGE * MINIMAP_SCALE;
	data->minimap.img = mlx_new_image(mlx, minimap_img_size, minimap_img_size);
	data->ray = gc_malloc(mlx->width * sizeof(t_ray));
}
