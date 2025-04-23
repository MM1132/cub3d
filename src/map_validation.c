/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:26:49 by joklein           #+#    #+#             */
/*   Updated: 2025/04/23 11:20:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	white_space_skip(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	put_colour(int i, char *line, uint32_t *color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (*color)
		return (write(2, "Error: invalide map\n", 21), 1);
	i = white_space_skip(line, i);
	while (line[i])
	{
		i++;
	}
	r = 225;
	g = 30;
	b = 0;
	*color = (r << 16) | (g << 8) | b;
	return (0);
}

int	put_texture(int i, char *line, char **ptr)
{
	int	u;
	int	v;
	int	fd;

	if (*ptr)
		return (write(2, "Error: invalide map\n", 21), 1);
	i = white_space_skip(line, i);
	u = i;
	while (line[i] && line[i] != '\n')
		i++;
	*ptr = malloc(i - u + 1);
	v = 0;
	while (line[u] && line[u] != '\n')
	{
		(*ptr)[v] = line[u];
		u++;
		v++;
	}
	(*ptr)[v] = '\0';
	fd = open(*ptr, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: invalide map\n", 21), 1);
	close(fd);
	return (0);
}

int	check_texture(int i, char *text, char *line, t_data *data)
{
	int	num_ret;

	num_ret = 0;
	if (!strncmp(text, "NO", 3))
		num_ret = put_texture(i, line, &data->no_texture);
	else if (!strncmp(text, "SO", 3))
		num_ret = put_texture(i, line, &data->so_texture);
	else if (!strncmp(text, "WE", 3))
		num_ret = put_texture(i, line, &data->we_texture);
	else if (!strncmp(text, "EA", 3))
		num_ret = put_texture(i, line, &data->ea_texture);
	else if (!strncmp(text, "F", 2))
	{
		num_ret = put_colour(i, line, &data->floor_color);
		printf("color = 0x%06X\n", data->floor_color);
	}
	else if (!strncmp(text, "C", 2))
	{
		num_ret = put_colour(i, line, &data->ceiling_color);
		printf("color = 0x%06X\n", data->ceiling_color);
	}
	else
		return (write(2, "Error: invalide map\n", 21), 1);
	return (num_ret);
}

int	map_invalid(char **argv, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		u;
	char	text[3];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: Open failed\n", 20), 1);
	line = get_next_line(fd);
	while (line)
	{
		text[0] = '\0';
		text[1] = '\0';
		text[2] = '\0';
		i = 0;
		u = 0;
		i = white_space_skip(line, i);
		while (line[i] && line[i] != ' ' && line[i] != '\t' && u < 3)
		{
			text[u] = line[i];
			if (text[2] != '\0')
				return (write(2, "Error: invalide map\n", 21), 1);
			i++;
			u++;
		}
		if (line[0] != '\n')
			if (check_texture(i, text, line, data) == 1)
				return (1);
		free(line);
		line = get_next_line(fd);
	}
	(void)argv;
	return (0);
}
