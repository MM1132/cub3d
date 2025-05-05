/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:35:23 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 01:48:30 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include "rect.h"
#include <stdbool.h>

typedef struct s_collision
{
	bool	colliding;
	t_vec2	dir;
	double	amount;
}	t_collision;

t_collision	rect_collides_rect(t_rect *rect_1, t_rect *rect_2);
t_collision	circle_collides_rect(t_circle *circle, t_rect *rect);

#endif
