/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_to_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:19:13 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:26:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision_detection.h"
#include "vector.h"
#include <math.h>
#include <stdio.h>

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

	normal = vec_normalize( \
		vec_subtract(closest_vertex(circle->pos, rect->vertices), circle->pos));

	index = 0;
	while (index < 4)
	{
		rect_projections[index] = vec_dot_product(&normal, &rect->vertices[index]);
		index++;
	}
	t_vec2 circle_start = vec_add(circle->pos, vec_multiply_n(normal, circle->radius));
	circle_projection[0] = vec_dot_product(&normal, &circle_start);
	t_vec2 circle_end = vec_subtract(circle->pos, vec_multiply_n(normal, circle->radius));
	circle_projection[1] = vec_dot_product(&normal, &circle_end);

	amount = get_overlap_amount(rect_projections, circle_projection);
	return ((t_collision) { amount > 0, vec_multiply_n(normal, -1), amount });
}

static t_collision	rect_collision(int side_index, t_rect *rect, t_circle *circle)
{
	t_vec2	side;
	double	rect_projections[4];
	double	circle_projections[2];
	t_vec2	circle_correction;
	double	amount;

	// Get normalized vector
	side = vec_subtract(rect->vertices[side_index], rect->vertices[(side_index + 1) % 4]);
	vec_swap_xy(&side);
	side.y *= -1;
	side = vec_normalize(side);

	// Get rect vertex projections
	side_index = -1;
	while (++side_index < 4)
		rect_projections[side_index] = vec_dot_product(&side, &rect->vertices[side_index]);

	// Get the two circle projections
	circle_correction = vec_add(circle->pos, vec_multiply_n(side, circle->radius));
	circle_projections[0] = vec_dot_product(&side, &circle_correction);
	circle_correction = vec_subtract(circle->pos, vec_multiply_n(side, circle->radius));
	circle_projections[1] = vec_dot_product(&side, &circle_correction);

	// Get the amount of overlap
	amount = get_overlap_amount(rect_projections, circle_projections);
	return ((t_collision) { amount > 0, side, amount });
}

// Filter out all collisions that are colliding
// Get the ones with the lowest amount
// If there are two collisions both with the lowest amount,
// ...return the one that has the highest dot product to the closest vertex
t_collision	filter_collisions(t_collision collisions[5], t_circle *circle, t_rect *rect)
{
	t_vec2		direction_vec;
	int			index;
	t_collision	lowest_collision;
	double		highest_dot_product;
	double		new_dot_product;

	direction_vec = vec_subtract(circle->pos, closest_vertex(circle->pos, rect->vertices));
	lowest_collision.colliding = false;
	index = 0;
	while (index < 5)
	{
		if (collisions[index].colliding)
		{
			if (lowest_collision.colliding == false)
			{
				lowest_collision = collisions[index];
				highest_dot_product = vec_dot_product(&collisions[index].dir, &direction_vec);
			}
			else
			{
				if (collisions[index].amount < lowest_collision.amount)
				{
					lowest_collision = collisions[index];
					highest_dot_product = vec_dot_product(&collisions[index].dir, &direction_vec);
				}
				else if (collisions[index].amount == lowest_collision.amount)
				{
					new_dot_product = vec_dot_product(&collisions[index].dir, &direction_vec);
					if (new_dot_product > highest_dot_product)
					{
						lowest_collision = collisions[index];
						highest_dot_product = new_dot_product;
					}
				}
			}
		}
		else
		{
			lowest_collision.colliding = false;
			return (lowest_collision);
		}
		index++;
	}
	return (lowest_collision);
}

t_collision	circle_collides_rect(t_circle *circle, t_rect *rect)
{
	int	side_index;
	t_collision	collisions[5];

	side_index = 0;
	while (side_index < 4)
	{
		collisions[side_index] = rect_collision(side_index, rect, circle);
		side_index++;
	}
	collisions[4] = circle_collision(circle, rect);
	return (filter_collisions(collisions, circle, rect));
}
