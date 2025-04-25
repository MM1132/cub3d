/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:58:38 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 12:59:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double	vec_length(t_vec2 vec)
{
	double	length;

	length = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	return (length);
}
