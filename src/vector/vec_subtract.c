/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:26:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 14:47:36 by rreimann         ###   ########.fr       */
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
