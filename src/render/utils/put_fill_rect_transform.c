/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fill_rect_transform.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:56:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:58:45 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "rect.h"
#include "garbage_collector.h"
#include "vector.h"
#include <limits.h>
#include <math.h>

typedef struct s_intersection
{
	t_vec2	line1_dir;
	t_vec2	line2_dir;
	t_vec2	between_starts;
	double	denominator;
	double	parameter1;
	double	parameter2;
}	t_intersection;

typedef struct	s_intersection_result
{
	bool	collinear;
	t_vec2	point;
}	t_intersection_result;

static t_intersection_result	intersection_of_two_lines(t_line line1, t_line line2)
{
	t_intersection			values;

	values.line1_dir = vec_subtract(line1.end, line1.start);
	values.line2_dir = vec_subtract(line2.end, line2.start);
	
	values.denominator = vec_cross_product(&values.line1_dir, &values.line2_dir);
	
	// If lines are parallel, then there is no intersection point
	if (values.denominator == 0)
		return ((t_intersection_result) { false, (t_vec2) { 0, 0 } });

	values.between_starts = vec_subtract(line2.start, line1.start);

	values.parameter1 = vec_cross_product(&values.between_starts, &values.line2_dir) / values.denominator;
	values.parameter2 = vec_cross_product(&values.between_starts, &values.line1_dir) / values.denominator;

	// Check if the intersection point of the lines is in the segments
	// If not, we just return
	if ((values.parameter1 < 0 || values.parameter1 > 1) && \
		(values.parameter2 < 0 || values.parameter2 > 1))
		return ((t_intersection_result) { false, (t_vec2) { 0, 0 } });
	
	// Here, we can calculate and return the true intersection point
	return ((t_intersection_result) { true, (t_vec2) { \
		line1.start.x + values.parameter1 * values.line1_dir.x, \
		line1.start.y + values.parameter1 * values.line1_dir.y } });
}

// Make sure that we only have one line out of all the 4 results
// Essentially we just need the point with the smallest x
// And the point with the biggest x. 
// Easy! 
static t_line	filter_results(t_intersection_result results[4])
{
	t_line	return_value;
	int		index;

	return_value.start.x = __DBL_MAX__;
	return_value.end.x = __DBL_MIN__;
	index = -1;
	while (index++ < 3)
	{
		if (results[index].collinear)
		{
			if (results[index].point.x < return_value.start.x)
			{
				return_value.start.x = results[index].point.x;
				return_value.start.y = results[index].point.y;
			}
			if (results[index].point.x > return_value.end.x)
			{
				return_value.end.x = results[index].point.x;
				return_value.end.y = results[index].point.y;
			}
		}
	}
	return (return_value);
}

static t_line	calculate_line_points(t_line *horizontal, t_rect *rect)
{
	int						line_index;
	t_intersection_result	results[4];
	t_line					line;

	line_index = 0;
	while (line_index < 4)
	{
		line.start = rect->vertices[line_index];
		line.end = rect->vertices[(line_index + 1) % 4];
		results[line_index] = \
			intersection_of_two_lines(*horizontal, line);
		line_index++;
	}
	return (filter_results(results));
}

void	put_fill_rect_transform( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
)
{
	t_bounds	rect_bounds;
	t_line		horizontal_line;
	t_line		fill_line;
	uint32_t	x;

	// Transform the rect
	rect_rotate_to(rect, transform);
	rect_bounds = rect_get_bounds(rect);

	// Loop through all the y coordinates of the rect
	horizontal_line.start = vec_new(rect_bounds.left, rect_bounds.top);
	horizontal_line.end = vec_new(rect_bounds.right, rect_bounds.top);
	while (horizontal_line.start.y <= rect_bounds.bottom)
	{
		fill_line = calculate_line_points(&horizontal_line, rect);
		if (fill_line.start.x < 0)
			fill_line.start.x = 0;
		if (fill_line.start.x != __DBL_MAX__ && fill_line.end.x != __DBL_MIN__)
		{
			x = (uint32_t)fill_line.start.x - 1;
			while (++x <= (uint32_t)ceil(fill_line.end.x))
				put_pixel(img, x, (uint32_t)horizontal_line.start.y, color);
		}
		horizontal_line.start.y += 1;
		horizontal_line.end.y = horizontal_line.start.y;
	}
}
