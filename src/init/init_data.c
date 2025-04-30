/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 23:58:59 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void init_data(t_data *data)
{
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
}
