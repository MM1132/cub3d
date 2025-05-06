/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/05/05 21:10:15 by rreimann         ###   ########.fr       */
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
	gc_free(data->no_texture);
	gc_free(data->we_texture);
	gc_free(data->so_texture);
	gc_free(data->ea_texture);
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

	// Hooks
	mlx_cursor_hook(g_mlx, cursor_hook, &data);
	mlx_scroll_hook(g_mlx, scroll_hook, &data);
	mlx_key_hook(g_mlx, key_hook, &data);
	mlx_resize_hook(g_mlx, resize_hook, &data);
	mlx_loop_hook(g_mlx, main_loop_hook, &data);
	mlx_loop(g_mlx);

	// Cleanup
	mlx_terminate(g_mlx);
	free_data(&data);
	gc_free_all();
	return (0);
}
