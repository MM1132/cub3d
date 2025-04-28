/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:43:49 by joklein           #+#    #+#             */
/*   Updated: 2025/04/28 12:31:32 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (width == 0)
				break ;
			if ((size_t)width > data->map.width)
				data->map.width = width;
			width = -1;
			height++;
		}
		width++;
		i++;
	}
	if ((size_t)width > data->map.width)
		data->map.width = width;
	data->map.height = height;
}
