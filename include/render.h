/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/29 19:41:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "vector.h"

// Minimap rendering
void	render_minimap(t_data *data);
void	render_minimap_grid(t_data *data);
void	render_minimap_player(t_data *data);
t_vec2	pos_to_minimap(t_vec2 pos);

// Utility draw functions
void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);
void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color);
void	put_fill(mlx_image_t *img, uint32_t color);

// Draw a circle given the center point of the circle
void	put_circle(mlx_image_t *img, t_vec2 pos, int radius, uint32_t color);

//
void	ray_cast(t_data *data);

#endif
