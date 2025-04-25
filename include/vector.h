/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:15:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 13:00:49 by rreimann         ###   ########.fr       */
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

// Normalize a vector, so that the distance from the center is 1
t_vec2	vec_normalize(t_vec2 vec);

// Multiply a vector by a given number
t_vec2	vec_multiply_n(t_vec2 vec, double n);

// Return the length of the given vector
double	vec_length(t_vec2 vec);

#endif
