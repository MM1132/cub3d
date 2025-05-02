/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_to_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:19:13 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 02:23:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision_detection.h"
#include "vector.h"
#include <math.h>

static double	get_overlap_amount(double p1[4], double p2[2])
{
	double	min1;
	double	max1;
	double	min2;
	double	max2;

	min1 = fmin(fmin(p1[0], p1[1]), fmin(p1[2], p1[3]));
	max1 = fmax(fmax(p1[0], p1[1]), fmax(p1[2], p1[3]));
	min2 = fmin(p2[0], p2[1]);
	max2 = fmax(p2[0], p2[1]);
	return (fmax(0, fmin(max1, max2) - fmax(min1, min2)));
}

static t_vec2	closest_vertex(t_vec2 pos, t_vec2 vertices[4])
{
	double	distance;
	double	smallest_distance;
	int		index;
	int		smallest_index;

	index = 0;
	smallest_index = index;
	smallest_distance = vec_length(vec_subtract(vertices[index], pos));
	while (index < 3)
	{
		index++;
		distance = vec_length(vec_subtract(vertices[index], pos));
		if (distance < smallest_distance)
		{
			smallest_distance = distance;
			smallest_index = index;
		}
	}
	return (vertices[smallest_index]);
}

// We also need the rect, because we need to project the vertices of the rect
static t_collision	circle_collision(t_circle *circle, t_rect *rect)
{
	int		index;
	double	rect_projections[4];
	double	circle_projection[2];
	t_vec2	normal;
	double	amount;

	normal = vec_subtract(closest_vertex(circle->pos, rect->vertices), circle->pos);
	// vec_swap_xy(&normal);
	// normal.y *= -1;
	normal = vec_normalize(normal);

	index = 0;
	while (index < 4)
	{
		rect_projections[index] = vec_dot_product(&normal, &rect->vertices[index]);
		index++;
	}
	// One side
	t_vec2 circle_start = vec_add(circle->pos, vec_multiply_n(normal, circle->radius));
	circle_projection[0] = vec_dot_product(&normal, &circle_start);
	// The other side
	t_vec2 circle_end = vec_subtract(circle->pos, vec_multiply_n(normal, circle->radius));
	circle_projection[1] = vec_dot_product(&normal, &circle_end);

	amount = get_overlap_amount(rect_projections, circle_projection);
	return ((t_collision) { amount > 0, normal, amount });
}

static t_collision	rect_collision(int side_index, t_rect *rect, t_circle *circle)
{
	t_vec2	side;
	int		index;
	double	rect_projections[4];
	double	circle_projection[2];
	double	amount;

	side = vec_subtract(rect->vertices[(side_index + 1) % 4], rect->vertices[side_index]);
	vec_swap_xy(&side);
	side.y *= -1;
	side = vec_normalize(side);

	// Loop through all the points of the rect
	index = 0;
	while (index < 4)
	{
		rect_projections[index] = vec_dot_product(&side, &rect->vertices[index]);
		index++;
	}
	// One side
	t_vec2 circle_start = vec_add(circle->pos, vec_multiply_n(side, circle->radius));
	circle_projection[0] = vec_dot_product(&side, &circle_start);
	// The other side
	t_vec2 circle_end = vec_subtract(circle->pos, vec_multiply_n(side, circle->radius));
	circle_projection[1] = vec_dot_product(&side, &circle_end);
	
	amount = get_overlap_amount(rect_projections, circle_projection);
	return ((t_collision) { amount > 0, side, amount });
}

t_collision	circle_collides_rect(t_circle *circle, t_rect *rect)
{
	t_collision	smallest_collision;
	t_collision	collision;
	int			side_index;

	smallest_collision.colliding = false;
	side_index = 0;
	// There are 4 sides on a rect
	while (side_index < 4)
	{
		collision = rect_collision(side_index, rect, circle);
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

		collision = circle_collision(circle, rect);
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

		side_index++;
	}
	return (smallest_collision);
}
