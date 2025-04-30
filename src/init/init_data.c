/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 15:15:06 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void init_data(t_data *data)
{
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->ray = NULL;
	data->map.height = 0;
	data->map.width = 0;
	data->floor_color = 0;
	data->ceiling_color = 0;
	init_player(&data->player);
	init_inputs(&data->inputs);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
}
