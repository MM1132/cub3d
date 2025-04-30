/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:39:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 19:48:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

// This is filling a rect assuming no rotation
void	put_fill_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	size_t	x;
	size_t	y;

	x = rect->a.x;
	while (x < rect->b.x)
	{
		y = rect->a.y;
		while (y < rect->c.y)
		{
			put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
