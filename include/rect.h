/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:55:30 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 21:43:59 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
#define RECT_H

#include "vector.h"
#include "shape_types.h"

// Create and return a new transformed rect based on a reference
void		rect_rotate_to(t_rect *rect, t_transform transform);

// Create a rect between two points (a & c)
t_rect		rect_new2(t_vec2 a, t_vec2 c);

// Create a new rect starting from a specific position
// ... then automatically calculate all the other points for it
t_rect		rect_from_point(t_vec2 point, double width, double height);

t_bounds	rect_get_bounds(t_rect *rect);

#endif
