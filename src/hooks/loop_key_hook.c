/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:35:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/24 17:04:32 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

// TODO: Separate keyboard input, updating variables, and rendering
void	loop_key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	data->down_keys.key_w = mlx_is_key_down(mlx, MLX_KEY_W);
	data->down_keys.key_a = mlx_is_key_down(mlx, MLX_KEY_A);
	data->down_keys.key_s = mlx_is_key_down(mlx, MLX_KEY_S);
	data->down_keys.key_d = mlx_is_key_down(mlx, MLX_KEY_D);

	// TODO: Change this later
	// Change player speed
	if (data->down_keys.key_w)
		data->player.speed_y -= 0.01;
	if (data->down_keys.key_s)
		data->player.speed_y += 0.01;
	if (data->down_keys.key_a)
		data->player.speed_x -= 0.01;
	if (data->down_keys.key_d)
		data->player.speed_x += 0.01;
	
	data->player.speed_x *= 0.95;
	data->player.speed_y *= 0.95;

	// Move the player
	// Adding speed to position
	data->player.pos_x += data->player.speed_x;
	data->player.pos_y += data->player.speed_y;

	render_minimap(data);
}
