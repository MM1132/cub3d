/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:57:02 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 15:14:11 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

// void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param)
void	cursor_hook(double xpos, double ypos, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->inputs.mouse_pos.x = xpos;
	data->inputs.mouse_pos.y = ypos;
}
