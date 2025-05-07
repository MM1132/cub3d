/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/05/06 16:14:44 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "render.h"
#include "settings.h"
#include "MLX42.h"

mlx_t		*g_mlx = NULL;
int			g_map_value = 0;

void	gc_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map.tiles)
		return ;
	while (data->map.tiles[i])
	{
		gc_free(data->map.tiles[i]);
		i++;
	}
	gc_free(data->map.tiles);
}

static void	free_data(t_data *data)
{
	gc_free_map(data);
	mlx_delete_texture(data->texture.north);
	mlx_delete_texture(data->texture.east);
	mlx_delete_texture(data->texture.south);
	mlx_delete_texture(data->texture.west);
	mlx_delete_texture(data->texture.door);
	mlx_delete_image(g_mlx, data->minimap.img);
    mlx_delete_image(g_mlx, data->player.hand);
	gc_free(data->ray);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],
				'.'), ".cub", 5))
		return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	if (map_validation(argv, &data))
		return (1);
	init_minimap(&data);
	mlx_image_to_window(g_mlx, data.img, 0, 0);
	mlx_image_to_window(g_mlx, data.minimap.img, MINIMAP_MARGIN, MINIMAP_MARGIN);
	mlx_image_to_window(g_mlx, data.player.hand, \
		(int32_t)data.player.hand_original_pos.x, (int32_t)data.player.hand_original_pos.y);
	put_help();

	// Hooks
	mlx_cursor_hook(g_mlx, cursor_hook, &data);
	mlx_scroll_hook(g_mlx, scroll_hook, &data);
	mlx_key_hook(g_mlx, key_hook, &data);
	mlx_resize_hook(g_mlx, resize_hook, &data);
	mlx_mouse_hook(g_mlx, mouse_hook, &data);
	mlx_loop_hook(g_mlx, main_loop_hook, &data);
	mlx_loop(g_mlx);

	// Cleanup
	mlx_terminate(g_mlx);
	free_data(&data);
	gc_free_all();
	return (0);
}
