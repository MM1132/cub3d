/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:57:02 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 16:07:05 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"
#include "settings.h"

// void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param)
void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->inputs.mouse_locked)
	{
		data->inputs.mouse_pos.y = g_mlx->height / 2;
		data->inputs.diff_x = xpos - data->inputs.mouse_pos.x;
		data->inputs.mouse_pos.x = g_mlx->width / 2;
		vec_rotate_to(&data->player.dir, \
			data->inputs.diff_x * PLAYER_ROTATION_SPEED);
		mlx_set_mouse_pos(g_mlx, g_mlx->width / 2, g_mlx->height / 2);
	}
	else
	{
		data->inputs.diff_x = xpos - data->inputs.mouse_pos.x;
		vec_rotate_to(&data->player.dir, \
			data->inputs.diff_x * PLAYER_ROTATION_SPEED);
		data->inputs.mouse_pos.x = xpos;
		data->inputs.mouse_pos.y = ypos;
	}
}
