/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 15:08:24 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	mlx_texture_t	*hand_texture;

	player->pos = vec_new(3, 3);
	player->speed = vec_new(0, 0);
	player->dir = vec_new(1, 0);
	player->center = vec_new(0, 0);

	hand_texture = mlx_load_png("./assets/texture/hand.png");
	player->hand = mlx_texture_to_image(g_mlx, hand_texture);
	double amount = (g_mlx->height * 0.5) / player->hand->height;
	mlx_resize_image(player->hand, player->hand->width * amount, player->hand->height * amount);
	player->hand_original_pos = vec_new(g_mlx->width - player->hand->width, \
		g_mlx->height - player->hand->height);
}
