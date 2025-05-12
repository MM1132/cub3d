/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_to_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:19:13 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 12:53:43 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision_detection.h"
#include "vector.h"
#include <math.h>
#include <stdio.h>

// We also need the rect, because we need to project the vertices of the rect
static t_collision	circle_collision(t_circle *circle, t_rect *rect)
{
	int		index;
	double	rect_projections[4];
	double	circle_projection[2];
	t_vec2	normal;
	double	amount;
	t_vec2	circle_point;

	normal = vec_normalize(\
		vec_subtract(closest_vertex(circle->pos, rect->vertices), circle->pos));
	index = 0;
	while (index < 4)
	{
		rect_projections[index] = vec_dot_product(&normal, \
			&rect->vertices[index]);
		index++;
	}
	circle_point = vec_add(circle->pos, vec_multiply_n(normal, circle->radius));
	circle_projection[0] = vec_dot_product(&normal, &circle_point);
	circle_point = vec_subtract(circle->pos, vec_multiply_n(normal, \
		circle->radius));
	circle_projection[1] = vec_dot_product(&normal, &circle_point);
	amount = get_overlap_amount(rect_projections, circle_projection);
	return ((t_collision){amount > 0, vec_multiply_n(normal, -1), amount});
}

static t_collision	rect_collision(int side_index, \
	t_rect *rect, t_circle *circle)
{
	t_vec2	side;
	double	rect_projections[4];
	double	circle_projections[2];
	t_vec2	circle_correction;
	double	amount;

	side = vec_subtract(rect->vertices[side_index], \
		rect->vertices[(side_index + 1) % 4]);
	vec_swap_xy(&side);
	side.y *= -1;
	side = vec_normalize(side);
	side_index = -1;
	while (++side_index < 4)
		rect_projections[side_index] = vec_dot_product(&side, \
			&rect->vertices[side_index]);
	circle_correction = vec_add(circle->pos, \
		vec_multiply_n(side, circle->radius));
	circle_projections[0] = vec_dot_product(&side, &circle_correction);
	circle_correction = vec_subtract(circle->pos, vec_multiply_n(side, \
		circle->radius));
	circle_projections[1] = vec_dot_product(&side, &circle_correction);
	amount = get_overlap_amount(rect_projections, circle_projections);
	return ((t_collision){amount > 0, side, amount});
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
	index = -1;
	while (++index < 5)
	{
		if (!collisions[index].colliding)
			return (lowest_collision.colliding = false, lowest_collision);
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
	return (lowest_collision);
}

t_collision	circle_collides_rect(t_circle *circle, t_rect *rect)
{
	int			side_index;
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
