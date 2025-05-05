/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:29:23 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 20:55:37 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"

// 1. Origin to 0
// 2. Rotate from the origin
// 3. Set origin back
void	rect_rotate_to(t_rect *rect, t_transform transform)
{
	vec_subtract_to(&rect->vertices[0], &transform.origin);
	vec_subtract_to(&rect->vertices[1], &transform.origin);
	vec_subtract_to(&rect->vertices[2], &transform.origin);
	vec_subtract_to(&rect->vertices[3], &transform.origin);
	vec_rotate_to(&rect->vertices[0], transform.rotation);
	vec_rotate_to(&rect->vertices[1], transform.rotation);
	vec_rotate_to(&rect->vertices[2], transform.rotation);
	vec_rotate_to(&rect->vertices[3], transform.rotation);
	vec_add_to(&rect->vertices[0], &transform.origin);
	vec_add_to(&rect->vertices[1], &transform.origin);
	vec_add_to(&rect->vertices[2], &transform.origin);
	vec_add_to(&rect->vertices[3], &transform.origin);
}
