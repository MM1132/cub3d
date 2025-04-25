/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:50:50 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 18:53:14 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2	vec_rotate(t_vec2 vec, double rad)
{
	t_vec2	new_vec;

	new_vec.x = vec.x * cos(rad) - vec.y * sin(rad);
	new_vec.y = vec.x * sin(rad) + vec.y * cos(rad);
	return (new_vec);
}
