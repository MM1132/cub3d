/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:24:40 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 01:22:23 by rreimann         ###   ########.fr       */
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
	
	// difference between the two points
	diff = vec_subtract(end, start);

	// steps needed to plot the line
	steps = fmax(fabs(diff.x), fabs(diff.y));

	// Increment with each step
	increment_x = diff.x / steps;
	increment_y = diff.y / steps;

	// Draw the line
	current_step = 0;
	while (current_step < steps)
	{
		put_pixel(img, (uint32_t)start.x, (uint32_t)start.y, color);

		start.x += increment_x;
		start.y += increment_y;

		current_step++;
	}
}

// void	put_fast_line(mlx_image_t *img, t_line *line, uint32_t color)
// {
	
// }
