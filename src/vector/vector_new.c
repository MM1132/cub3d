/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:17:53 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/24 16:19:35 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	vector_new(double x, double y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
