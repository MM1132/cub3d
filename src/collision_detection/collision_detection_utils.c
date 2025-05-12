/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:35:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 12:42:04 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision_detection.h"
#include "vector.h"
#include <math.h>

double	get_overlap_amount(double p1[4], double p2[2])
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

t_vec2	closest_vertex(t_vec2 pos, t_vec2 vertices[4])
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
