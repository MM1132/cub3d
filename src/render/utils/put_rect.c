/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:34:07 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 19:47:21 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color)
{
	put_line(img, rect->a, rect->b, color);
	put_line(img, rect->b, rect->c, color);
	put_line(img, rect->c, rect->d, color);
	put_line(img, rect->d, rect->a, color);
}
