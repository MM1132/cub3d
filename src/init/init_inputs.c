/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:40:08 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:20:19 by rreimann         ###   ########.fr       */
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
	mlx_get_mouse_pos(mlx, &mouse_x, &mouse_y);
	inputs->mouse_pos.x = mouse_x;
	inputs->mouse_pos.y = mouse_y;
	inputs->toggle_minimap_grid = false;
	inputs->toggle_minimap_rays = true;
	inputs->toggle_minimap_rotation = true;
}
