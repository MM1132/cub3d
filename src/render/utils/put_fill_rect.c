/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:39:09 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 12:03:48 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	put_fill_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < rect->width)
	{
		y = 0;
		while (y < rect->height)
		{
			put_pixel(img, rect->x + x, rect->y + y, color);
			y++;
		}
		x++;
	}
}
