/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:17:27 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 11:22:42 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	render_crosshair(t_data *data)
{
	t_vec2	screen_center;
	t_line	line_vertical;
	t_line	line_horizontal;

	screen_center.x = g_mlx->width / 2;
	screen_center.y = g_mlx->height / 2;
	line_vertical.start = vec_new(screen_center.x, screen_center.y - 10);
	line_vertical.end = vec_new(screen_center.x, screen_center.y + 10);
	line_horizontal.start = vec_new(screen_center.x - 10, screen_center.y);
	line_horizontal.end = vec_new(screen_center.x + 10, screen_center.y);
	put_line(data->img, line_vertical.start, line_vertical.end, 0xFFFFFFFF);
	put_line(data->img, line_horizontal.start, line_horizontal.end, 0xFFFFFFFF);
}
