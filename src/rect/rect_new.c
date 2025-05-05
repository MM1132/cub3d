/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:55:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:32:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "vector.h"
#include <math.h>

t_rect	rect_new2(t_vec2 a, t_vec2 b)
{
	t_rect	new_rect;

	new_rect.vertices[0] = a;
	new_rect.vertices[1].x = b.x;
	new_rect.vertices[1].y = a.y;
	new_rect.vertices[2] = b;
	new_rect.vertices[3].x = a.x;
	new_rect.vertices[3].y = b.y;
	return (new_rect);
}

t_rect	rect_from_point(t_vec2 point, double width, double height)
{
	t_rect	new_rect;

	new_rect.vertices[0].x = point.x;
	new_rect.vertices[0].y = point.y;

	new_rect.vertices[1].x = point.x + width;
	new_rect.vertices[1].y = point.y;

	new_rect.vertices[2].x = point.x + width;
	new_rect.vertices[2].y = point.y + height;

	new_rect.vertices[3].x = point.x;
	new_rect.vertices[3].y = point.y + height;

	return (new_rect);
}
