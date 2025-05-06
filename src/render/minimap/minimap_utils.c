/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:40:42 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:41:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "vector.h"
#include <math.h>

void	transform_vec_to_rotation(t_data *data, t_vec2 *vec)
{
	t_vec2	transform_rotation;

	transform_rotation.x = data->minimap.img->width / 2;
	transform_rotation.y = data->minimap.img->height / 2;
	vec_subtract_to(vec, &transform_rotation);
	vec_rotate_to(vec, M_PI * 1.5 - atan2(data->player.dir.y, \
		data->player.dir.x));
	vec_add_to(vec, &transform_rotation);
}
