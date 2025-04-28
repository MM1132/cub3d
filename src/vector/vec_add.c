/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:44:48 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 17:04:01 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec_add(t_vec2 first, t_vec2 second)
{
	t_vec2	new_vec;

	new_vec.x = first.x + second.x;
	new_vec.y = first.y + second.y;
	return (new_vec);
}

void	vec_add_to(t_vec2 *vec, t_vec2 *addition)
{
	vec->x += addition->x;
	vec->y += addition->y;
}
