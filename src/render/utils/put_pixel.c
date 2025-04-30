/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:48 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 14:39:55 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "MLX42.h"

void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		mlx_put_pixel(img, x, y, color);
}
