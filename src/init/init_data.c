/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/09 10:16:28 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

void init_texture(t_data *data)
{
	data->texture.door_c = mlx_load_png("./assets/texture/door_closed.png");
	if (!data->texture.door_c)
	{
		write(2, "door_file not found\n", 20);
		exit(1);
	}
	data->texture.door_o = mlx_load_png("./assets/texture/door_open.png");
	if (!data->texture.door_o)
	{
		mlx_delete_texture(data->texture.door_c);
		write(2, "door_file not found\n", 20);
		exit(1);
	}
}

void	init_data(t_data *data)
{
	init_texture(data);
	mlx_set_setting(MLX_FULLSCREEN, true);
	g_mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->img = mlx_new_image(g_mlx, WIDTH, HEIGHT);
	data->texture.north = NULL;
	data->texture.east = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->map.tiles = NULL;
	data->map.map_valid = 0;
	init_player(&data->player);
	init_inputs(&data->inputs);
	data->ray = gc_malloc(g_mlx->width * sizeof(t_ray));
}
