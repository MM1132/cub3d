/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:26:49 by joklein           #+#    #+#             */
/*   Updated: 2025/04/25 16:29:11 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

static char	**splitter(char *line)
{
	char	**split;
	int		i;
	int		u;

	split = safe_split(line, ',');
	if (!split)
		return (write(2, "Error: split failed\n", 20), NULL);
	i = 0;
	while (split[i])
	{
		u = 0;
		u = white_space_skip(split[i], u);
		if (!ft_isdigit(split[i][u]))
			return (free_split(split), err_mssg(), NULL);
		while (split[i][u] && ft_isdigit(split[i][u]))
			u++;
		u = white_space_skip(split[i], u);
		if (split[i][u] != '\0' && split[i][u] != '\n')
			return (free_split(split), err_mssg(), NULL);
		i++;
	}
	if (i != 3)
		return (free_split(split), err_mssg(), NULL);
	return (split);
}

static int	put_color(int i, char *line, uint32_t *color)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	if (*color)
		return (err_mssg());
	i = white_space_skip(line, i);
	split = splitter(&line[i]);
	if (!split)
		return (1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_split(split), err_mssg());
	*color = (r << 16) | (g << 8) | b;
	return (free_split(split), 0);
}

static int	put_texture(int i, char *line, char **ptr)
{
	int	u;
	int	fd;

	if (*ptr)
		return (err_mssg());
	i = white_space_skip(line, i);
	u = i;
	while (line[u] && line[u] != '\n')
		u++;
	*ptr = gc_malloc(u - i + 1);
	u = 0;
	while (line[i] && line[i] != '\n')
		(*ptr)[u++] = line[i++];
	(*ptr)[u] = '\0';
	fd = open(*ptr, O_RDONLY);
	if (fd == -1)
		return (err_mssg());
	close(fd);
	return (0);
}

static int	check_texture(int i, char *text, char *line, t_data *data)
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
		num_ret = put_color(i, line, &data->floor_color);
	else if (!strncmp(text, "C", 2))
		num_ret = put_color(i, line, &data->ceiling_color);
	else
		return (err_mssg());
	return (map_value++, num_ret);
}

static void	fill_text(char text[3], char *line, int *i)
{
	int	u;

	u = 0;
	while (line[(*i)] && !white_space(line, (*i)) && u < 3)
		text[u++] = line[(*i)++];
}

int	map_validation(char **argv, t_data *data)
{
	char	*line;
	int		i;
	char	text[3];
	char	*file;

	file = read_file(argv);
	if (!file)
		return (1);
	line = safe_gnl(file);
	while (line)
	{
		ft_memset(text, '\0', 3);
		i = 0;
		i = white_space_skip(line, i);
		fill_text(text, line, &i);
		if (map_value == 6 && text[0] == '1')
			return (create_map(file, line, data));
		if (text[2] != '\0')
			return (err_mssg());
		if (text[0] != '\n' && check_texture(i, text, line, data) == 1)
			return (1);
		gc_free(line);
		line = safe_gnl(file);
	}
	return (err_mssg());
}
