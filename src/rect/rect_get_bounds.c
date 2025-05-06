/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_get_bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:59:22 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:54:52 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include <math.h>

t_bounds	rect_get_bounds(t_rect *rect)
{
	t_bounds	bounds;

	bounds.top = fmin(fmin(rect->vertices[0].y, rect->vertices[1].y), \
		fmin(rect->vertices[2].y, rect->vertices[3].y));
	bounds.bottom = fmax(fmax(rect->vertices[0].y, rect->vertices[1].y), \
		fmax(rect->vertices[2].y, rect->vertices[3].y));
	bounds.left = fmin(fmin(rect->vertices[0].x, rect->vertices[1].x), \
		fmin(rect->vertices[2].x, rect->vertices[3].x));
	bounds.right = fmax(fmax(rect->vertices[0].x, rect->vertices[1].x), \
		fmax(rect->vertices[2].x, rect->vertices[3].x));
	bounds.height = fabs(bounds.top - bounds.bottom) + 1;
	bounds.width = fabs(bounds.left - bounds.right) + 1;
	return (bounds);
}
