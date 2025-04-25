/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:04:01 by joklein           #+#    #+#             */
/*   Updated: 2025/04/25 16:27:42 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

static int	get_line(int line_num, char *file)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (file[i] && num < line_num)
	{
		if (file[i] == '\n')
			num++;
		i++;
	}
	return (i);
}

char	*safe_gnl(char *file)
{
	static int	line_num = 0;
	int			i;
	char		*line;
	size_t		num;

	i = get_line(line_num, file);
	num = 0;
	while (file[i + num] && file[i + num] != '\n')
		num++;
	if (file[i + num] == '\n')
		num++;
	line = gc_malloc(num + 1);
	num = 0;
	while (file[i + num] && file[i + num] != '\n')
	{
		line[num] = file[i + num];
		num++;
	}
	if (file[i + num] == '\n')
	{
		line[num] = file[i + num];
		num++;
	}
	line[num] = '\0';
	line_num++;
	return (line);
}

static char	*fill_temp_file(int len, char *file, char read_buffer[1])
{
	int		i;
	char	*temp_file;

	temp_file = gc_malloc(len + 2);
	i = 0;
	while (i < len)
	{
		temp_file[i] = file[i];
		i++;
	}
	temp_file[i++] = read_buffer[0];
	temp_file[i] = '\0';
	return (temp_file);
}

static char	*create_file(int fd, char *file, char *temp_file)
{
	int		read_status;
	char	read_buffer[1];
	int		len;

	read_status = read(fd, read_buffer, 1);
	while (read_status > 0)
	{
		len = 0;
		while (file[len])
			len++;
		temp_file = fill_temp_file(len, file, read_buffer);
		gc_free(file);
		file = temp_file;
		read_status = read(fd, read_buffer, 1);
	}
	if (read_status == -1)
		return (write(2, "Error: Read failed\n", 20), NULL);
	return (file);
}

char	*read_file(char **argv)
{
	int		fd;
	char	*file;
	char	*temp_file;

	temp_file = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: Open failed\n", 20), NULL);
	file = gc_malloc(1);
	file[0] = '\0';
	file = create_file(fd, file, temp_file);
	close(fd);
	return (file);
}
