/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:13:16 by joklein           #+#    #+#             */
/*   Updated: 2025/04/30 08:44:29 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

int	round_double(double numtoround)
{
	if (numtoround >= 0)
		return (int)(numtoround + 0.5);
	else
		return (int)(numtoround - 0.5);
}

t_vec2	vec_add_value(t_vec2 vec, double value)
{
	t_vec2	new_vec;

	new_vec.x = vec.x + value;
	new_vec.y = vec.y + value;
	return (new_vec);
}
