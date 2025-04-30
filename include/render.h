/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 17:28:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "vector.h"

typedef struct s_line
{
	t_vec2	start;
	t_vec2	end;
}	t_line;

typedef struct s_pixel_transform
{
	t_vec2	origin;
	double	rotation;
}	t_pixel_transform;

// Minimap rendering
void	render_minimap(t_data *data);
void	minimap_render_grid(t_data *data, t_vec2 offset);
void	render_minimap_player(t_data *data);

// UTILITY DRAW FUNCTIONS
void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void	put_pixel_rotation( \
	mlx_image_t *img, \
	t_vec2 pos, \
	t_pixel_transform transform,
	uint32_t color \
);

void	put_fill_rect(mlx_image_t *img, t_rect *rect, uint32_t color);
void	put_fill_rect_rotation( \
	mlx_image_t *img, \
	t_rect *rect, \
	t_pixel_transform transform, \
	uint32_t color \
);

// Draws only the lie borders of the rectangle
void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);

void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color);
void	put_line_rotation( \
	mlx_image_t *img, \
	t_line *line, \
	t_pixel_transform transform, \
	uint32_t color \
);

void	put_fill(mlx_image_t *img, uint32_t color);

// Draw a circle given the center point of the circle
void	put_circle(mlx_image_t *img, t_vec2 pos, int radius, uint32_t color);

//
void	ray_cast(t_data *data);

#endif
