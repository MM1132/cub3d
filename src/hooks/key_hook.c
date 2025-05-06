/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:47:47 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:57:41 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_G && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_grid = !data->inputs.toggle_minimap_grid;
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_rotation = \
			!data->inputs.toggle_minimap_rotation;
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		data->inputs.toggle_minimap_rays = !data->inputs.toggle_minimap_rays;
}
