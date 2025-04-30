/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 20:58:47 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_TYPES_H
#define SHAPE_TYPES_H

#include "vector.h"

typedef struct s_rect
{
	t_vec2	a;
	t_vec2	b;
	t_vec2	c;
	t_vec2	d;
}	t_rect;

typedef struct s_bounds
{
	double	top;
	double	left;
	double	right;
	double	bottom;
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
