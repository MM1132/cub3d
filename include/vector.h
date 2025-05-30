/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:15:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 15:37:40 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vec2_int
{
	int		x;
	int		y;
}			t_vec2_int;

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

// Create a new vector with given x and y
t_vec2		vec_new(double x, double y);
t_vec2_int	vec_new_int(int x, int y);

// Add two vectors together
t_vec2		vec_add(t_vec2 first, t_vec2 second);
t_vec2		vec_add_n(t_vec2 vec, double n);
void		vec_add_to(t_vec2 *vec, t_vec2 *addition);
void		vec_add_n_to(t_vec2 *vec, double n);

// Subtract one vector from another
t_vec2		vec_subtract(t_vec2 first, t_vec2 second);
t_vec2		vec_subtract_n(t_vec2 first, double n);
void		vec_subtract_to(t_vec2 *first, t_vec2 *second);
void		vec_subtract_n_to(t_vec2 *vec, double n);

// Normalize a vector, so that the distance from the center is 1
t_vec2		vec_normalize(t_vec2 vec);

// Multiply a vector by a given number
t_vec2		vec_multiply_n(t_vec2 vec, double n);
void		vec_multiply_n_to(t_vec2 *vec, double n);

// Return the length of the given vector
double		vec_length(t_vec2 vec);

// Rotate the vector by the number of radians
t_vec2		vec_rotate(t_vec2 vec, double rad);
void		vec_rotate_to(t_vec2 *vec, double rad);

// Products
double		vec_cross_product(t_vec2 *vec1, t_vec2 *vec2);
double		vec_dot_product(t_vec2 *vec, t_vec2 *point);

void		vec_swap_xy(t_vec2 *vec);

#endif
