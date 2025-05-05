/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:56:18 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "vector.h"
# include "rect.h"
# include "shape_types.h"

// Minimap rendering
void	minimap_render(t_data *data);
void	minimap_render_grid(t_data *data);
void	render_minimap_border(t_data *data);
void	render_minimap_rays(t_data *data);
void	render_minimap_player(t_data *data);

// UTILITY DRAW FUNCTIONS
void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void	put_pixel_rotation( \
	mlx_image_t *img, \
	t_vec2 pos, \
	t_transform transform,
	uint32_t color \
);

void	put_fill_rect(mlx_image_t *img, t_rect *rect, uint32_t color);
void	put_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
);
void	put_fill_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
);
void	put_fill_rect_transform( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_transform transform, \
	uint32_t color \
);

// Draws only the lie borders of the rectangle
void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);

void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color);
void	put_line_rotation( \
	mlx_image_t *img, \
	t_line *line, \
	t_transform transform, \
	uint32_t color \
);

void	put_fill(mlx_image_t *img, uint32_t color);

// Draw a circle given the center point of the circle
void	put_circle(mlx_image_t *img, t_vec2 pos, int radius, uint32_t color);

void	ray_cast(t_data *data);

#endif
