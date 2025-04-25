/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:16:24 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 15:17:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_fill(mlx_image_t *img, uint32_t color)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
