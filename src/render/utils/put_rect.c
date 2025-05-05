/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:34:07 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 23:46:10 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	put_line(img, rect->vertices[0], rect->vertices[1], color);
	put_line(img, rect->vertices[1], rect->vertices[2], color);
	put_line(img, rect->vertices[3], rect->vertices[2], color);
	put_line(img, rect->vertices[0], rect->vertices[3], color);

	put_line(img, rect->vertices[0], rect->vertices[2], color);
	put_line(img, rect->vertices[3], rect->vertices[1], color);
}
