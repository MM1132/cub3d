/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/04/29 12:08:34 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "render.h"
#include "settings.h"

mlx_t		*mlx = NULL;
int			map_value = 0;

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
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	mlx_image_to_window(mlx, data.img, 0, 0);
	mlx_image_to_window(mlx, data.minimap_img, MINIMAP_MARGIN, MINIMAP_MARGIN);
	if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],
				'.'), ".cub", 5))
		return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	if (map_validation(argv, &data))
		return (1);
	mlx_cursor_hook(mlx, &cursor_hook, &data);
	mlx_scroll_hook(mlx, scroll_hook, &data);
	mlx_loop_hook(mlx, &main_loop_hook, &data);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	free_data(&data);
	gc_free_all();
	return (0);
}
