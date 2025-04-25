/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:52:03 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/25 12:53:54 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec_multiply_n(t_vec2 vec, double n)
{
	t_vec2	new_vec;

	new_vec.x = vec.x * n;
	new_vec.y = vec.y * n;
	return (new_vec);
}
