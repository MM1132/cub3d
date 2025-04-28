/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 16:06:01 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	put_circle(mlx_image_t *img, t_vec2 pos, int radius, uint32_t color)
{
	t_vec2	current;

	current.y = -radius;
	while (current.y < radius)
	{
		current.x = -radius;
		while (current.x < radius)
		{
			if (pow(current.x, 2) + pow(current.y, 2) <= pow(radius, 2))
				mlx_put_pixel(img, current.x + pos.x, current.y + pos.y, color);
			current.x++;
		}
		current.y++;
	}
}
