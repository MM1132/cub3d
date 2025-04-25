/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/04/25 10:03:40 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

mlx_t *mlx = NULL;

static t_map	create_temp_map()
{
	size_t	map_width = 10;
	size_t	map_height = 10;
	t_map	new_map;

	new_map.width = map_width;
	new_map.height = map_height;

	// First, allocate memory for the map
	new_map.tiles = gc_malloc(map_height * sizeof(t_tile *));
	for (size_t	y = 0; y < map_height; y++)
	{
		new_map.tiles[y] = gc_malloc(sizeof(t_tile) * map_width);
	}

	// Then, set values for the map tiles
	for (size_t x = 0; x < map_width; x++)
	{
		for (size_t y = 0; y < map_height; y++)
		{
			if (x == 0 || y == 0 || x == map_width - 1 || y == map_height - 1)
			{
				// Create a wall
				new_map.tiles[y][x].tile_type = TILE_WALL;
			}
			else 
			{
				// Create a floor
				new_map.tiles[y][x].tile_type = TILE_FLOOR;
			}
			new_map.tiles[y][x].state = 0;
		}
	}
	// Also, create one random block in the middle
	new_map.tiles[4][4].tile_type = TILE_WALL;

	return (new_map);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data data;

	init_data(&data);
	data.map = create_temp_map();
	mlx_image_to_window(mlx, data.img, 0, 0);

	// mlx_image_to_window(mlx, data->img, 0, 0);
	// if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],'.'), ".cub", 5))
	// 	return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	// if (map_invalid(argv, data))
	// 	return (1);

	mlx_loop_hook(mlx, &main_loop_hook, &data);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	gc_free_all();
	return (0);
}
