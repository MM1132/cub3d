/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 16:38:01 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "cub3d.h"
#include "vector.h"

// Minimap rendering
void	render_minimap(t_data *data);
void	render_minimap_grid(t_data *data);
void	render_minimap_player(t_data *data);

// Utility draw functions
void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);
void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color);
void	put_fill(mlx_image_t *img, uint32_t color);

// Draw a circle given the center point of the circle
void	put_circle(mlx_image_t *img, t_vec2 pos, int radius, uint32_t color);

#endif
