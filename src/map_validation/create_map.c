/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:53:01 by joklein           #+#    #+#             */
/*   Updated: 2025/04/24 17:41:33 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

void add_one_line(char *line, t_data *data)
{
    int i;
    int u;
    char **temp_map;

    i = 0;
    while(data->map[i])
        i++;
    temp_map = gc_malloc(sizeof(char *) * (i+2));
    temp_map[i+1] = NULL;
    i = 0;
    while(data->map[i])
    {
        temp_map[i] = data->map[i];
        i++;
    }
    gc_free(data->map);
    data->map = temp_map;
    u = 0;
    while (line[u] && line[u] != '\n')
		u++;
	data->map[i] = gc_malloc(u + 1);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		data->map[0][i] = line[i];
		i++;
	}
    data->map[0][i] = '\0';
}

int	create_map(char *file, char *line, t_data *data)
{
	data->map = gc_malloc(sizeof(char *));
	data->map[0] = NULL;
    add_one_line(line, data);
    gc_free(line);
    // line = safe_gnl(file);
	printf("%s\n", data->map[0]);
    // gc_free(line);
    gc_free(file);
	return (0);
}
