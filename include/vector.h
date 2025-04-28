/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:15:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 17:19:42 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

// Create a new vector with given x and y
t_vec2	vec_new(double x, double y);

// Add two vectors together
t_vec2	vec_add(t_vec2 first, t_vec2 second);
void	vec_add_to(t_vec2 *vec, t_vec2 *addition);

// Subtract one vector from another
t_vec2	vec_subtract(t_vec2 first, t_vec2 second);

// Normalize a vector, so that the distance from the center is 1
t_vec2	vec_normalize(t_vec2 vec);

// Multiply a vector by a given number
t_vec2	vec_multiply_n(t_vec2 vec, double n);
void	vec_multiply_n_to(t_vec2 *vec, double n);

// Return the length of the given vector
double	vec_length(t_vec2 vec);

// Rotate the vector by the number of radians
t_vec2	vec_rotate(t_vec2 vec, double rad);
void	vec_rotate_to(t_vec2 *vec, double rad);

#endif
