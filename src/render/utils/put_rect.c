/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:34:07 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 12:21:33 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	put_line(img, vec_new(rect->x, rect->y), \
		vec_new(rect->x + rect->width - 1, rect->y), color);
	put_line(img, vec_new(rect->x, rect->y), \
		vec_new(rect->x, rect->y + rect->height - 1), color);
	put_line(img, vec_new(rect->x, rect->y + rect->height - 1), \
		vec_new(rect->x + rect->width - 1, rect->y + rect->height - 1), color);
	put_line(img, vec_new(rect->x + rect->width - 1, rect->y), \
		vec_new(rect->x + rect->width - 1, rect->y + rect->height - 1), color);
}
