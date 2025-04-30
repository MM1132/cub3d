/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:29:06 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 15:31:46 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "MLX42.h"

void	put_fill_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_pixel_transform transform, \
	uint32_t color \
)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < rect->width)
	{
		y = 0;
		while (y < rect->height)
		{
			put_pixel_rotation(img, vec_new(rect->x + x, rect->y + y), transform, color);
			y++;
		}
		x++;
	}
}
