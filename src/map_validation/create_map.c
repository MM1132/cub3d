/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:53:01 by joklein           #+#    #+#             */
/*   Updated: 2025/04/24 18:55:00 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

void	add_one_line(char *line, t_data *data)
{
	int		i;
	int		u;
	t_tile	**temp_map;

	i = 0;
	while (data->map.tiles[i])
		i++;
	temp_map = gc_malloc(sizeof(char *) * (i + 2));
	temp_map[i + 1] = NULL;
	i = 0;
	while (data->map.tiles[i])
	{
		temp_map[i] = data->map.tiles[i];
		i++;
	}
	gc_free(data->map.tiles);
	data->map.tiles = temp_map;
	u = 0;
	while (line[u] && line[u] != '\n')
    u++;
	data->map.tiles[i] = gc_malloc(u + 1);
	i = 0;
	// while (line[i] && line[i] != '\n')
	// {
    //     if (line[i] == '1')
    //     data->map.tiles[0][i].tile_type = TILE_WALL;
	// 	else if (line[i] == '0')
    //     data->map.tiles[0][i].tile_type = TILE_FLOOR;
	// 	i++;
	// }
	// data->map.tiles[0][i].tile_type = '\0';
}

int	create_map(char *file, char *line, t_data *data)
{
    data->map.tiles = gc_malloc(sizeof(char *));
	data->map.tiles[0] = NULL;
	add_one_line(line, data);
	gc_free(line);
	// line = safe_gnl(file);
	// gc_free(line);
	gc_free(file);
	return (0);
}
