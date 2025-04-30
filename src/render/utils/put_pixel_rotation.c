/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:20:53 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 15:20:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"
#include "MLX42.h"

void	put_pixel_rotation( \
	mlx_image_t *img, \
	t_vec2 pos, \
	t_pixel_transform transform, \
	uint32_t color \
)
{
	vec_subtract_to(&pos, &transform.origin);
	vec_rotate_to(&pos, transform.rotation);
	vec_add_to(&pos, &transform.origin);
	
	put_pixel(img, pos.x, pos.y, color);
}
