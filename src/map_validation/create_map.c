/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:53:01 by joklein           #+#    #+#             */
/*   Updated: 2025/04/25 17:17:12 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

t_tile_type	ft_ctott(char c)
{
	t_tile_type	i;
	char		num;

	i = 0;
	num = '0';
	while (1)
	{
		if (c == num)
			break ;
		num++;
		i++;
	}
	return (i);
}

void	add_one_line(char *line, t_data *data, size_t num_line)
{
	int		i;
	size_t	u;
	t_tile	**temp_map;

	i = 0;
	while (data->map.tiles[i])
		i++;
	temp_map = gc_malloc(sizeof(t_tile *) * (i + 2));
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
	data->map.tiles[i] = gc_malloc(sizeof(t_tile) * data->map.width + 1);
	u = 0;
	while (u < data->map.width)
	{
		if (line[u] == '\0' || line[u] == '\n')
		{
			while (u < data->map.width)
			{
				data->map.tiles[i][u].tile_type = TILE_SPACE;
				u++;
			}
			break ;
		}
		if (line[u] == ' ')
			data->map.tiles[i][u].tile_type = TILE_SPACE;
		else if (line[u] == '1' || line[u] == '0')
			data->map.tiles[i][u].tile_type = ft_ctott(line[u]);
		else
		{
			data->map.tiles[i][u].tile_type = ft_ctott('0');
			data->player.pos_x = (double)u;
			data->player.pos_y = (double)num_line;
		}
		u++;
	}
	data->map.tiles[i][u].tile_type = '\0';
}

int	create_map(char *file, char *line, t_data *data)
{
	size_t	num_line;

	set_width_height(file, data);
	data->map.tiles = gc_malloc(sizeof(t_tile **));
	data->map.tiles[0] = NULL;
	num_line = 0;
	while (num_line < data->map.height)
	{
		add_one_line(line, data, num_line);
		gc_free(line);
		line = safe_gnl(file);
		num_line++;
	}
	gc_free(line);
	gc_free(file);
	return (0);
}
