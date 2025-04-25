/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/04/25 17:00:06 by joklein          ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_data	data;

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
