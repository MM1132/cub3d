/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:29:24 by joklein           #+#    #+#             */
/*   Updated: 2025/04/23 11:07:02 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_t *mlx = NULL;

void init_data(t_data *data)
{
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	init_data(data);
	if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strncmp(ft_strrchr(argv[1],'.'), ".cub", 5))
		return (write(2, "Error: Usage: ./cub3D <map.cub>\n", 33), 1);
	if (map_invalid(argv, data))
		return (1);
	mlx = mlx_init(1000, 600, "cub3D", true);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
