/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:03:53 by joklein           #+#    #+#             */
/*   Updated: 2025/05/05 21:10:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "garbage_collector.h"
#include "settings.h"

void	ray_malloc(t_data *data)
{
	if (data->ray)
		gc_free(data->ray);
	data->ray = gc_malloc(g_mlx->width * sizeof(t_ray));
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	g_mlx->height = height;
	g_mlx->width = width;
	ray_malloc(data);
}
