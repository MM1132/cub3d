/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:29:23 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 21:43:58 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"

void	rect_rotate_to(t_rect *rect, t_transform transform)
{
	// Origin to 0
	vec_subtract_to(&rect->a, &transform.origin);
	vec_subtract_to(&rect->b, &transform.origin);
	vec_subtract_to(&rect->c, &transform.origin);
	vec_subtract_to(&rect->d, &transform.origin);

	// Rotate from the origin
	vec_rotate_to(&rect->a, transform.rotation);
	vec_rotate_to(&rect->b, transform.rotation);
	vec_rotate_to(&rect->c, transform.rotation);
	vec_rotate_to(&rect->d, transform.rotation);

	// Set origin back
	vec_add_to(&rect->a, &transform.origin);
	vec_add_to(&rect->b, &transform.origin);
	vec_add_to(&rect->c, &transform.origin);
	vec_add_to(&rect->d, &transform.origin);
}
