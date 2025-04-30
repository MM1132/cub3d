/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_get_bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:59:22 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 21:02:24 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include <math.h>

t_bounds	rect_get_bounds(t_rect *rect)
{
	t_bounds	bounds;

	bounds.top = fmin(fmin(rect->a.y, rect->b.y), fmin(rect->c.y, rect->d.y));
	bounds.bottom = fmax(fmax(rect->a.y, rect->b.y), fmax(rect->c.y, rect->d.y));
	bounds.left = fmin(fmin(rect->a.x, rect->b.x), fmin(rect->c.x, rect->d.x));
	bounds.right = fmax(fmax(rect->a.x, rect->b.x), fmax(rect->c.x, rect->d.x));
	return (bounds);
}
