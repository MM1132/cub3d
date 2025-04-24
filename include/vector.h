/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:15:21 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/24 16:55:14 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vector2
{
	double	x;
	double	y;
}	t_vector2;

t_vector2	vector_new(double x, double y);

#endif
