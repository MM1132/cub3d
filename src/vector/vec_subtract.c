/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/30 22:38:28 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec_subtract(t_vec2 first, t_vec2 second)
{
	t_vec2	new_vec;

	new_vec.x = first.x - second.x;
	new_vec.y = first.y - second.y;
	return (new_vec);
}

t_vec2	vec_subtract_n(t_vec2 first, double n)
{
	t_vec2	new_vec;

	new_vec.x = first.x - n;
	new_vec.y = first.y - n;
	return (new_vec);
}
