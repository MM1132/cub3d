/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:28:18 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/24 18:08:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_down_keys(t_down_keys *down_keys)
{
	down_keys->key_w = false;
	down_keys->key_a = false;
	down_keys->key_s = false;
	down_keys->key_d = false;
}

static void	init_player(t_player *player)
{
	player->pos_x = 3;
	player->pos_y = 3;
	player->speed_x = 0;
	player->speed_y = 0;
	player->dir = vector_new(1, 0);
}

void init_data(t_data *data)
{
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	init_player(&data->player);
	init_down_keys(&data->down_keys);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
}
