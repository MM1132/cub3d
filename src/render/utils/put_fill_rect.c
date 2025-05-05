/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:39:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 18:52:35 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

// This is filling a rect assuming no rotation
void	put_fill_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	int	x;
	int	y;

	x = rect->vertices[0].x;
	while (x < rect->vertices[1].x)
	{
		y = rect->vertices[0].y;
		while (y < rect->vertices[2].y)
		{
			put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
