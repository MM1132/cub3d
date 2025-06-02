/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:05:40 by joklein           #+#    #+#             */
/*   Updated: 2025/05/12 17:49:29 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

static void	gc_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map.tiles)
		return ;
	while (data->map.tiles[i])
	{
		gc_free(data->map.tiles[i]);
		i++;
	}
	gc_free(data->map.tiles);
}

void	free_data(t_data *data)
{
	gc_free_map(data);
	mlx_delete_texture(data->texture.north);
	mlx_delete_texture(data->texture.east);
	mlx_delete_texture(data->texture.south);
	mlx_delete_texture(data->texture.west);
	mlx_delete_texture(data->texture.door_c);
	mlx_delete_texture(data->texture.door_o);
	mlx_delete_image(g_mlx, data->minimap.img);
	mlx_delete_image(g_mlx, data->player.hand);
	mlx_delete_image(g_mlx, data->img);
	gc_free(data->ray);
}
