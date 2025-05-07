/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:17:27 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 16:00:50 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include <math.h>

static void	render_line_towards_angle(t_data *data, \
	t_vec2 *screen_center, double angle)
{
	t_line	upper_line;

	upper_line.start = vec_add(*screen_center, \
		vec_multiply_n(vec_rotate(vec_new(1, 0), angle + M_PI_4 * 0.6), 10));
	upper_line.end = vec_add(*screen_center, \
		vec_multiply_n(vec_rotate(vec_new(1, 0), angle - M_PI_4 * 0.6), 10));
	vec_subtract_to(&upper_line.start, screen_center);
	vec_subtract_to(&upper_line.end, screen_center);
	vec_multiply_n_to(&upper_line.start, \
		vec_length(data->player.speed) * 30 + 1);
	vec_multiply_n_to(&upper_line.end, \
		vec_length(data->player.speed) * 30 + 1);
	vec_add_to(&upper_line.start, screen_center);
	vec_add_to(&upper_line.end, screen_center);
	put_line(data->img, upper_line.start, upper_line.end, 0x32ff32FF);
}

void	render_crosshair(t_data *data)
{
	t_vec2	screen_center;
	t_line	line_vertical;
	t_line	line_horizontal;

	screen_center.x = g_mlx->width / 2;
	screen_center.y = g_mlx->height / 2;
	line_vertical.start = vec_new(screen_center.x, screen_center.y - 3);
	line_vertical.end = vec_new(screen_center.x, screen_center.y + 4);
	line_horizontal.start = vec_new(screen_center.x - 3, screen_center.y);
	line_horizontal.end = vec_new(screen_center.x + 4, screen_center.y);
	put_line(data->img, line_vertical.start, line_vertical.end, 0x32ff32FF);
	put_line(data->img, line_horizontal.start, line_horizontal.end, 0x32ff32FF);
	vec_add_n_to(&screen_center, 1);
	render_line_towards_angle(data, &screen_center, 0);
	render_line_towards_angle(data, &screen_center, M_PI_2);
	render_line_towards_angle(data, &screen_center, -M_PI_2);
	render_line_towards_angle(data, &screen_center, M_PI);
}
