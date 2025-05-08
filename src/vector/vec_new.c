/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:17:53 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 17:08:37 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec_new(double x, double y)
{
	t_vec2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec2_int	vec_new_int(int x, int y)
{
	t_vec2_int	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
