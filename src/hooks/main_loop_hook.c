/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:35:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 02:31:22 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"
#include "render.h"
#include <math.h>

static void	get_keyboard_input(t_data *data)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	data->inputs.key_w = mlx_is_key_down(mlx, MLX_KEY_W);
	data->inputs.key_a = mlx_is_key_down(mlx, MLX_KEY_A);
	data->inputs.key_s = mlx_is_key_down(mlx, MLX_KEY_S);
	data->inputs.key_d = mlx_is_key_down(mlx, MLX_KEY_D);
	data->inputs.key_right = mlx_is_key_down(mlx, MLX_KEY_RIGHT);
	data->inputs.key_left = mlx_is_key_down(mlx, MLX_KEY_LEFT);
}

static void	main_game_loop(t_data *data)
{
	// Update
	get_keyboard_input(data);
	player_update(data);
	minimap_update(data);

	// Render
	put_fill(data->img, 0x000000FF);
	minimap_render(data);
	// if(data->ray[0].length != -1)
	// 	render_world(data);
	// ray_cast(data);
}

void	main_loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	main_game_loop(data);
}
