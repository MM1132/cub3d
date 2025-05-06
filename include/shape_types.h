/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 21:04:30 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_TYPES_H
# define SHAPE_TYPES_H

# include "vector.h"

typedef struct s_circle
{
	t_vec2	pos;
	double	radius;
}	t_circle;

typedef struct s_rect
{
	t_vec2	vertices[4];
}	t_rect;

typedef struct s_bounds
{
	double	top;
	double	left;
	double	right;
	double	bottom;
	double	width;
	double	height;
}	t_bounds;

typedef struct s_line
{
	t_vec2	start;
	t_vec2	end;
}	t_line;

typedef struct s_transform
{
	t_vec2	origin;
	double	rotation;
}	t_transform;

#endif
