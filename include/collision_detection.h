/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:35:23 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 12:36:58 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_DETECTION_H
# define COLLISION_DETECTION_H

# include "rect.h"
# include <stdbool.h>

typedef struct s_collision
{
	bool	colliding;
	t_vec2	dir;
	double	amount;
}	t_collision;

t_collision	rect_collides_rect(t_rect *rect_1, t_rect *rect_2);
t_collision	circle_collides_rect(t_circle *circle, t_rect *rect);

// Utils
double		get_overlap_amount(double p1[4], double p2[2]);
t_vec2		closest_vertex(t_vec2 pos, t_vec2 vertices[4]);

#endif
