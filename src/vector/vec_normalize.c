/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:54:22 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 13:00:46 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec_normalize(t_vec2 vec)
{
	t_vec2	normalized_vec;
	double	length;

	length = vec_length(vec);
	normalized_vec.x = vec.x / length;
	normalized_vec.y = vec.y / length;
	return (normalized_vec);
}
