/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:55:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 22:25:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "vector.h"

t_rect	rect_new2(t_vec2 a, t_vec2 c)
{
	t_rect	new_rect;

	new_rect.a = a;
	new_rect.b.x = c.x;
	new_rect.b.y = a.y;
	new_rect.c = c;
	new_rect.d.x = a.x;
	new_rect.d.y = c.x;
	return (new_rect);
}

t_rect	rect_from_point(t_vec2 point, double width, double height)
{
	t_rect	new_rect;

	new_rect.a.x = point.x;
	new_rect.a.y = point.y;

	new_rect.b.x = point.x + width - 1;
	new_rect.b.y = point.y;

	new_rect.c.x = point.x + width - 1;
	new_rect.c.y = point.y + height - 1;

	new_rect.d.x = point.x;
	new_rect.d.y = point.y + height - 1;

	return (new_rect);
}
