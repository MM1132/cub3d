/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:57:20 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 20:27:15 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_line_rotation( \
	mlx_image_t *img, \
	t_line *line, \
	t_transform transform, \
	uint32_t color \
)
{
	// Rotate both the points around origin
	vec_subtract_to(&line->start, &transform.origin);
	vec_subtract_to(&line->end, &transform.origin);

	vec_rotate_to(&line->start, transform.rotation);
	vec_rotate_to(&line->end, transform.rotation);

	vec_add_to(&line->start, &transform.origin);
	vec_add_to(&line->end, &transform.origin);

	put_line(img, line->start, line->end, color);
}
