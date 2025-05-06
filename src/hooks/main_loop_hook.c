/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:35:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 12:44:33 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"
#include "render.h"
#include <math.h>
#include "collision_detection.h"

static void	get_keyboard_input(t_data *data)
{
	if (mlx_is_key_down(g_mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g_mlx);
	data->inputs.key_w = mlx_is_key_down(g_mlx, MLX_KEY_W);
	data->inputs.key_a = mlx_is_key_down(g_mlx, MLX_KEY_A);
	data->inputs.key_s = mlx_is_key_down(g_mlx, MLX_KEY_S);
	data->inputs.key_d = mlx_is_key_down(g_mlx, MLX_KEY_D);
	data->inputs.key_right = mlx_is_key_down(g_mlx, MLX_KEY_RIGHT);
	data->inputs.key_left = mlx_is_key_down(g_mlx, MLX_KEY_LEFT);
}

static void	update(t_data *data)
{
	get_keyboard_input(data);
	player_update(data);
	minimap_update(data);
}

static void	render(t_data *data)
{
	put_fill(data->img, 0x000000FF);
	ray_cast(data);
	render_world(data);
	render_crosshair(data);
	minimap_render(data);
}

static void	main_game_loop(t_data *data)
{
	update(data);
	render(data);
}

void	main_loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	main_game_loop(data);
}
