/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:53:01 by joklein           #+#    #+#             */
/*   Updated: 2025/05/08 12:33:35 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

static void	set_player_map(t_data *data, char *line, size_t x, size_t y)
{
	data->map.tiles[y][x].tile_type = ft_atott('0');
	data->player.pos.x = (double)x + 0.5 - PLAYER_SIZE / 2;
	data->player.pos.y = (double)y + 0.5 - PLAYER_SIZE / 2;
	if (line[x] == 'N')
		data->player.dir = vec_new(0, -1);
	if (line[x] == 'E')
		data->player.dir = vec_new(1, 0);
	if (line[x] == 'S')
		data->player.dir = vec_new(0, 1);
	if (line[x] == 'W')
		data->player.dir = vec_new(-1, 0);
}

static void	fill_one_line(t_data *data, char *line, size_t x, size_t y)
{
	x = 0;
	while (x < data->map.width)
	{
		if (line[x] == '\0' || line[x] == '\n')
		{
			while (x < data->map.width)
			{
				data->map.tiles[y][x].tile_type = TILE_SPACE;
				x++;
			}
			break ;
		}
		if (line[x] == ' ')
			data->map.tiles[y][x].tile_type = TILE_SPACE;
		else if (ft_isdigit(line[x]))
			data->map.tiles[y][x].tile_type = ft_atott(line[x]);
		else
			set_player_map(data, line, x, y);
		data->map.tiles[y][x].state = 1;
		x++;
	}
	data->map.tiles[y][x].tile_type = '\0';
}

static void	add_one_line(char *line, t_data *data)
{
	int		y;
	size_t	x;
	t_tile	**temp_map;

	y = 0;
	while (data->map.tiles[y])
		y++;
	temp_map = gc_malloc(sizeof(t_tile *) * (y + 2));
	temp_map[y + 1] = NULL;
	x = 0;
	while (x < (size_t)y)
	{
		temp_map[x] = data->map.tiles[x];
		x++;
	}
	gc_free(data->map.tiles);
	data->map.tiles = temp_map;
	data->map.tiles[y] = gc_malloc(sizeof(t_tile) * data->map.width + 1);
	fill_one_line(data, line, x, y);
}

static int	valid_map_char(char cha, bool check)
{
	int			i;
	int			cha_int;
	static int	start_pos = 0;

	if (check == true)
		return (start_pos);
	if ((cha == 'N' || cha == 'E' || cha == 'S' || cha == 'W')
		&& start_pos == 0)
		return (start_pos++, 1);
	if (cha == ' ' || cha == '\n')
		return (1);
	i = 0;
	if (ft_isdigit(cha))
	{
		cha_int = ft_atoi(&cha);
		while (i < NUMBER_OF_TILES)
			if (i++ == cha_int)
				return (1);
	}
	return (0);
}

static bool	check_map_char(char *file, int i)
{
	int	u;

	while (file[i])
	{
		if (!valid_map_char(file[i], false))
			return (false);
		if (file[i] == '\n')
		{
			u = i - 1;
			while (white_space(file, u))
				u--;
			if (file[u] == '\n')
				break ;
		}
		i++;
	}
	if (!valid_map_char(file[i], true))
		return (false);
	while (file[i])
	{
		if (file[i] != '\n' && !white_space(file, i))
			return (false);
		i++;
	}
	return (true);
}

int	create_map(char *file, char *line, t_data *data)
{
	size_t	y;
	int		i;

	i = find_map_start(file);
	if (!check_map_char(file, i))
		return (err_mssg());
	set_width_height(file, data, i);
	data->map.tiles = gc_malloc(sizeof(t_tile **));
	data->map.tiles[0] = NULL;
	y = 0;
	while (y < data->map.height)
	{
		add_one_line(line, data);
		gc_free(line);
		line = safe_gnl(file);
		y++;
	}
	gc_free(line);
	gc_free(file);
	return (zeros_enclosed(data));
}
