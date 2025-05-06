/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:57:02 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 11:32:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"
#include "settings.h"

// void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param)
void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data	*data;
	double	diff_x;

	data = (t_data *)param;
	if (xpos != data->inputs.mouse_pos.x)
	{
		diff_x = xpos - data->inputs.mouse_pos.x;
		vec_rotate_to(&data->player.dir, diff_x * PLAYER_ROTATION_SPEED);
	}
	data->inputs.mouse_pos.x = xpos;
	data->inputs.mouse_pos.y = ypos;
}
