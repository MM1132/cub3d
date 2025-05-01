/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:29:06 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 21:17:19 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "MLX42.h"

// Find the first non-zero
// Check if everything else is the same sign
static bool	same_signs(double cross_products[4])
{
	int	index;
	int	first_non_zero_sign;

	index = 0;
	first_non_zero_sign = -1;
	while (index < 4)
	{
		if (cross_products[index] != 0)
			first_non_zero_sign = cross_products[index] < 0;
		index++;
	}
	if (first_non_zero_sign == -1)
		return (true);
	index = 0;
	while (index < 4)
	{
		if (cross_products[index] != 0 && \
			(cross_products[index] < 0) != first_non_zero_sign)
			return (false);
		index++;
	}
	return (true);
}

static bool	is_inside_rect(t_rect *rotated_rect, uint32_t x, uint32_t y)
{
	double	cross_products[4];
	t_vec2	point;
	t_vec2	first;
	t_vec2	second;

	point = vec_new(x, y);
	// One
	first = vec_subtract(rotated_rect->b, rotated_rect->a);
	second = vec_subtract(point, rotated_rect->a);
	cross_products[0] = vec_cross_product(&first, &second);
	// Two
	first = vec_subtract(rotated_rect->c, rotated_rect->b);
	second = vec_subtract(point, rotated_rect->b);
	cross_products[1] = vec_cross_product(&first, &second);
	// Three
	first = vec_subtract(rotated_rect->d, rotated_rect->c);
	second = vec_subtract(point, rotated_rect->c);
	cross_products[2] = vec_cross_product(&first, &second);
	// Four
	first = vec_subtract(rotated_rect->a, rotated_rect->d);
	second = vec_subtract(point, rotated_rect->d);
	cross_products[3] = vec_cross_product(&first, &second);
	return (same_signs(cross_products));
}

// We want to do the rotation of the rectangles
// 1. Rotate all the 4 points of the rectangle on the point of origin
// 2. With these new 4 points, and the origin rotated back to normal
// ... figure out the start_x and end_x, and start_y and end_y coordinates
// 3. Loop through the coordinates and with the use of cross product, determine
// ... whether or not each point is to be drawn within the rectangle or not
void	put_fill_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
)
{
	t_bounds	rect_bounds;
	uint32_t	x;
	uint32_t	y;

	rect_rotate_to(rect, transform);
	rect_bounds = rect_get_bounds(rect);

	// And now, based on the bounds, loop through all the coordinates of the rect
	x = rect_bounds.left;
	while (x < rect_bounds.right)
	{
		y = rect_bounds.top;
		while (y < rect_bounds.bottom)
		{
			// Now, here we have the possible coordinates of the rect pixel
			// We just need to figure out whether or not the position is within the rect or not
			if (is_inside_rect(rect, x, y))
				put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
