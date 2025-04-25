/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 15:17:40 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "cub3d.h"
#include "vector.h"

void	render_minimap(t_data *data);

// Utility draw functions
void	put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);
void	put_line(mlx_image_t *img, t_vec2 start, t_vec2 end, uint32_t color);
void	put_fill(mlx_image_t *img, uint32_t color);

#endif
