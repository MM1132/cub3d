/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:35:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 12:39:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

void	get_keyboard_input(t_data *data)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	data->down_keys.key_w = mlx_is_key_down(mlx, MLX_KEY_W);
	data->down_keys.key_a = mlx_is_key_down(mlx, MLX_KEY_A);
	data->down_keys.key_s = mlx_is_key_down(mlx, MLX_KEY_S);
	data->down_keys.key_d = mlx_is_key_down(mlx, MLX_KEY_D);
}

// TODO: Change this to the Vector system later
void update_player(t_data *data)
{
	if (data->down_keys.key_w)
		data->player.speed.y -= PLAYER_ACCELERATION;
	if (data->down_keys.key_s)
		data->player.speed.y += PLAYER_ACCELERATION;
	if (data->down_keys.key_a)
		data->player.speed.x -= PLAYER_ACCELERATION;
	if (data->down_keys.key_d)
		data->player.speed.x += PLAYER_ACCELERATION;
	
	data->player.speed.x *= PLAYER_SPEED_DECREASE_MULTIPLIER;
	data->player.speed.y *= PLAYER_SPEED_DECREASE_MULTIPLIER;

	data->player.pos.x += data->player.speed.x;
	data->player.pos.y += data->player.speed.y;
}

void	main_game_loop(t_data *data)
{
	get_keyboard_input(data);
	update_player(data);
}

void	main_loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	main_game_loop(data);
	render_minimap(data);
}
