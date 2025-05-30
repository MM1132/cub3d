/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:43:49 by joklein           #+#    #+#             */
/*   Updated: 2025/05/09 10:21:34 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tile_type	ft_atott(char c)
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

int	find_map_start(char *file)
{
	int	i;
	int	count_args;

	i = 0;
	count_args = 0;
	while (file[i])
	{
		if (file[i] == 'N' || file[i] == 'S' || file[i] == 'W' || file[i] == 'E'
			|| file[i] == 'F' || file[i] == 'C')
		{
			while (file[i] != '\n')
				i++;
			count_args++;
		}
		i++;
		if (count_args == 6)
			break ;
	}
	while (file[i] != '1')
		i++;
	while (file[i] != '\n')
		i--;
	i++;
	return (i);
}

static bool	two_line_break(char *file, int i)
{
	int	x;

	x = i - 1;
	while (white_space(file, x))
		x--;
	if (file[x] == '\n')
		return (true);
	return (false);
}

void	set_width_height(char *file, t_data *data, int i)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (two_line_break(file, i))
				break ;
			if ((size_t)width > data->map.width)
				data->map.width = width;
			width = -1;
			height++;
		}
		width++;
		i++;
	}
	if (file[i] == '\0')
		height++;
	if ((size_t)width > data->map.width)
		data->map.width = width;
	data->map.height = height;
}

int	valid_map_char(char cha, bool check)
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
