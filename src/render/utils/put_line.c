/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:24:40 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:32:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "vector.h"
#include "render.h"
#include <math.h>

void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color)
{
	t_vec2	diff;
	int		steps;
	double	increment_x;
	double	increment_y;
	int		current_step;

	diff = vec_subtract(end, start);
	steps = fmax(fabs(diff.x), fabs(diff.y));
	increment_x = diff.x / steps;
	increment_y = diff.y / steps;
	current_step = 0;
	while (current_step < steps)
	{
		put_pixel(img, (uint32_t)start.x, (uint32_t)start.y, color);
		start.x += increment_x;
		start.y += increment_y;
		current_step++;
	}
}
