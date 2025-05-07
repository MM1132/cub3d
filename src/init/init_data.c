/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 15:52:15 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

void	init_data(t_data *data)
{
	g_mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->img = mlx_new_image(g_mlx, WIDTH, HEIGHT);
	data->texture.north = NULL;
	data->texture.east = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.door = mlx_load_png("./assets/texture/door_closed.png");
	if (!data->texture.door)
	{
		write(2, "door_file not found\n", 20);
		exit(1);
	}
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->map.tiles = NULL;
	init_player(&data->player);
	init_inputs(&data->inputs);
	data->ray = gc_malloc(g_mlx->width * sizeof(t_ray));
}
