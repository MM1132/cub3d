/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:29:23 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 21:41:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"

void	rect_rotate_to(t_rect *rect, t_transform transform)
{
	// Origin to 0
	vec_subtract_to(&rect->vertices[0], &transform.origin);
	vec_subtract_to(&rect->vertices[1], &transform.origin);
	vec_subtract_to(&rect->vertices[2], &transform.origin);
	vec_subtract_to(&rect->vertices[3], &transform.origin);

	// Rotate from the origin
	vec_rotate_to(&rect->vertices[0], transform.rotation);
	vec_rotate_to(&rect->vertices[1], transform.rotation);
	vec_rotate_to(&rect->vertices[2], transform.rotation);
	vec_rotate_to(&rect->vertices[3], transform.rotation);

	// Set origin back
	vec_add_to(&rect->vertices[0], &transform.origin);
	vec_add_to(&rect->vertices[1], &transform.origin);
	vec_add_to(&rect->vertices[2], &transform.origin);
	vec_add_to(&rect->vertices[3], &transform.origin);
}
