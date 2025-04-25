/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 10:28:58 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_down_keys(t_down_keys *down_keys)
{
	down_keys->key_w = false;
	down_keys->key_a = false;
	down_keys->key_s = false;
	down_keys->key_d = false;
}

void	init_player(t_player *player)
{
	player->pos = vector_new(3, 3);
	player->speed = vector_new(0, 0);
	player->dir = vector_new(1, 0);
}
