/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_to_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:59:30 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 01:15:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision_detection.h"
#include "rect.h"
#include "vector.h"
#include "cub3d.h"
#include "settings.h"
#include <math.h>

// p here stands for "projection", but it was too much to write it out
static double	get_overlap_amount(double p1[4], double p2[4])
{
	double	min1;
	double	max1;
	double	min2;
	double	max2;

	min1 = fmin(fmin(p1[0], p1[1]), fmin(p1[2], p1[3]));
	max1 = fmax(fmax(p1[0], p1[1]), fmax(p1[2], p1[3]));
	min2 = fmin(fmin(p2[0], p2[1]), fmin(p2[2], p2[3]));
	max2 = fmax(fmax(p2[0], p2[1]), fmax(p2[2], p2[3]));
	return (fmax(0, fmin(max1, max2) - fmax(min1, min2)));
}

// In case of a collision, return the overlapping amount for the passed side of `main` rect
static t_collision	side_collision(int side_index, t_rect *main, t_rect *other)
{
	t_vec2	side;
	int		index;
	double	rect_1_projections[4];
	double	rect_2_projections[4];
	double	amount;

	side = vec_subtract(main->vertices[(side_index + 1) % 4], main->vertices[side_index]);
	vec_swap_xy(&side);
	side.y *= -1;
	side = vec_normalize(side);

	// So now we have the side of the rectangle
	// We must project points to it from both rectangles
	index = 0;
	while (index < 4)
	{
		rect_1_projections[index] = vec_dot_product(&side, &main->vertices[index]);
		rect_2_projections[index] = vec_dot_product(&side, &other->vertices[index]);
		index++;
	}

	amount = get_overlap_amount(rect_1_projections, rect_2_projections);
	return ((t_collision) { amount > 0, side, amount });
}

t_collision	rect_collides_rect(t_rect *rect_1, t_rect *rect_2)
{
	int			side_index;
	t_collision	smallest_collision;
	t_collision	collision;

	smallest_collision.colliding = false;
	side_index = 0;
	// There are 4 sides on a rect
	while (side_index < 4)
	{
		collision = side_collision(side_index, rect_1, rect_2);
		if (collision.colliding)
		{
			if (smallest_collision.colliding == false)
				smallest_collision = collision;
			else if (collision.colliding && collision.amount < smallest_collision.amount)
				smallest_collision = collision;
		}
		else
		{
			smallest_collision.colliding = false;
			break ;
		};

		collision = side_collision(side_index, rect_2, rect_1);
		if (collision.colliding)
		{
			if (smallest_collision.colliding == false)
				smallest_collision = collision;
			else if (collision.colliding && collision.amount < smallest_collision.amount)
				smallest_collision = collision;
		}
		else
		{
			smallest_collision.colliding = false;
			break ;
		}
		
		side_index++;
	}
	// If we got through all the sides for both rects,
	// It means we have a collision
	return (smallest_collision);
}
