/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/05/12 17:48:27 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "garbage_collector.h"
#include "render.h"
#include "settings.h"

mlx_t	*g_mlx = NULL;

void	start_hooks(t_data *data)
{
	mlx_cursor_hook(g_mlx, cursor_hook, data);
	mlx_scroll_hook(g_mlx, scroll_hook, data);
	mlx_key_hook(g_mlx, key_hook, data);
	mlx_resize_hook(g_mlx, resize_hook, data);
	mlx_mouse_hook(g_mlx, mouse_hook, data);
	mlx_loop_hook(g_mlx, main_loop_hook, data);
	mlx_loop(g_mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],
				'.'), ".cub", 5))
		return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	init_data(&data);
	if (map_validation(argv, &data))
		return (1);
	init_minimap(&data);
	mlx_image_to_window(g_mlx, data.img, 0, 0);
	mlx_image_to_window(g_mlx, data.minimap.img, MINIMAP_MARGIN,
		MINIMAP_MARGIN);
	mlx_image_to_window(g_mlx, data.player.hand,
		(int32_t)data.player.hand_original_pos.x,
		(int32_t)data.player.hand_original_pos.y);
	put_help();
	start_hooks(&data);
	free_data(&data);
	mlx_terminate(g_mlx);
	gc_free_all();
	return (0);
}
