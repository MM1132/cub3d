/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 15:10:10 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_inputs(t_inputs *inputs)
{
	inputs->key_w = false;
	inputs->key_a = false;
	inputs->key_s = false;
	inputs->key_d = false;
	inputs->mouse_pos = vec_new(0, 0);

}

void	init_player(t_player *player)
{
	player->pos = vec_new(3, 3);
	player->speed = vec_new(0, 0);
	player->dir = vec_new(1, 0);
}
