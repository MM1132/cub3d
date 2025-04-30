/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rect_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:20:01 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 22:21:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
)
{
	rect_rotate_to(rect, transform);
	put_rect(img, rect, color);
}
