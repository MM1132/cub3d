/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/04/24 18:23:07 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

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
	gc_free(data);
}

// static t_map	create_temp_map(void)
// {
// 	size_t	map_width;
// 	size_t	map_height;
// 	t_map	new_map;

// 	map_width = 10;
// 	map_height = 10;
// 	new_map.width = map_width;
// 	new_map.height = map_height;
// 	// First, allocate memory for the map
// 	new_map.tiles = gc_malloc(map_height * sizeof(t_tile *));
// 	for (size_t y = 0; y < map_height; y++)
// 	{
// 		new_map.tiles[y] = gc_malloc(sizeof(t_tile) * map_width);
// 	}
// 	// Then, set values for the map tiles
// 	for (size_t x = 0; x < map_width; x++)
// 	{
// 		for (size_t y = 0; y < map_height; y++)
// 		{
// 			if (x == 0 || y == 0 || x == map_width - 1 || y == map_height - 1)
// 			{
// 				// Create a wall
// 				new_map.tiles[y][x].tile_type = TILE_WALL;
// 			}
// 			else
// 			{
// 				// Create a floor
// 				new_map.tiles[y][x].tile_type = TILE_FLOOR;
// 			}
// 			new_map.tiles[y][x].state = 0;
// 		}
// 	}
// 	// Also, create one random block in the middle
// 	new_map.tiles[4][4].tile_type = TILE_WALL;
// 	return (new_map);
// }

int	main(int argc, char **argv)
{
	t_data	data;

	// (void)argc;
	// (void)argv;
	// data.map = gc_create_temp_map();
	init_data(&data);
	mlx_image_to_window(mlx, data.img, 0, 0);
	if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],
				'.'), ".cub", 5))
		return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	if (map_validation(argv, &data))
		return (1);
	mlx_loop_hook(mlx, &loop_key_hook, &data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_data(&data);
	gc_free_all();
	return (0);
}
