/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:47:47 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/08 12:43:01 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data		*data;
	t_vec2_int	tile_pos;
	t_tile		*facing_tile;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_G && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_grid = !data->inputs.toggle_minimap_grid;
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_rotation = \
			!data->inputs.toggle_minimap_rotation;
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_rays = !data->inputs.toggle_minimap_rays;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		if (data->inputs.mouse_locked)
		{
			data->inputs.mouse_locked = false;
			mlx_set_cursor_mode(g_mlx, MLX_MOUSE_NORMAL);
		}
		else
			mlx_close_window(g_mlx);
	}
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		minimap_set_range(data, data->minimap.range - 1);
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		minimap_set_range(data, data->minimap.range + 1);
	else if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_target_player = !data->inputs.toggle_minimap_target_player;
	else if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		if (data->player.facing_tile.distance > 2)
			return ;
		tile_pos = data->player.facing_tile.pos;
		facing_tile = &data->map.tiles[tile_pos.y][tile_pos.x];
		if (facing_tile->tile_type == TILE_DOOR)
		{
			if (facing_tile->state == false)
				facing_tile->state = true;
			else
				facing_tile->state = false;
		}
	}
}
