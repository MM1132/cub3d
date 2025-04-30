/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:03:53 by joklein           #+#    #+#             */
/*   Updated: 2025/04/30 15:54:26 by joklein          ###   ########.fr       */
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
	data->ray = gc_malloc(mlx->width * sizeof(t_ray));
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx->height = height;
	mlx->width = width;
	ray_malloc(data);
}
