/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:24:40 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 12:03:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "vector.h"
#include "render.h"
#include <math.h>

void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color)
{
	t_vec2	diff;
	size_t	steps;
	double	increment_x;
	double	increment_y;
	size_t	current_step;
	
	// difference between the two points
	diff = vec_subtract(end, start);

	// printf("DiffX: %f\n", diff.x);
	// printf("DiffY: %f\n", diff.y);

	// steps needed to plot the line
	if (diff.x > diff.y)
		steps = abs((int)diff.x);
	else
		steps = abs((int)diff.y);

	// printf("Steps: %ld\n", steps);
	
	// Increment with each step
	increment_x = diff.x / (double)steps;
	increment_y = diff.y / (double)steps;

	// printf("increment_x: %f\n", increment_x);
	// printf("increment_y: %f\n", increment_y);

	// Draw the line
	current_step = 0;
	while (current_step < steps)
	{
		if (start.x >= 0 && start.y >= 0 && start.x < img->width && start.y < img->height)
		{
			put_pixel(img, start.x, start.y, color);
		}

		start.x += increment_x;
		start.y += increment_y;

		current_step++;
	}
}
