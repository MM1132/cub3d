/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_inputs(t_inputs *inputs)
{
	int32_t	mouse_x;
	int32_t	mouse_y;

	inputs->key_w = false;
	inputs->key_a = false;
	inputs->key_s = false;
	inputs->key_d = false;
	// inputs->toggle_grid = false;
	mlx_get_mouse_pos(mlx, &mouse_x, &mouse_y);
	inputs->mouse_pos.x = mouse_x;
	inputs->mouse_pos.y = mouse_y;
}

void	init_player(t_player *player)
{
	player->pos = vec_new(3, 3);
	player->speed = vec_new(0, 0);
	player->dir = vec_new(1, 0);
}
