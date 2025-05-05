/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:53:53 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:53:26 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	four_keys(t_data *data)
{
	if (data->inputs.key_w && data->inputs.key_a && data->inputs.key_s && \
		data->inputs.key_d)
	{
		return (1);
	}
	return (0);
}

int	three_keys(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w && data->inputs.key_a && data->inputs.key_d)
		return (1);
	else if (data->inputs.key_a && data->inputs.key_w && data->inputs.key_s)
		return (vec_rotate_to(speed, -M_PI_2), 1);
	else if (data->inputs.key_s && data->inputs.key_a && data->inputs.key_d)
		return (vec_rotate_to(speed, -M_PI), 1);
	else if (data->inputs.key_d && data->inputs.key_w && data->inputs.key_s)
		return (vec_rotate_to(speed, M_PI_2), 1);
	return (0);
}

int	two_keys(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w && data->inputs.key_s)
		return (1);
	else if (data->inputs.key_a && data->inputs.key_d)
		return (vec_rotate_to(speed, -M_PI_2), 1);
	else if (data->inputs.key_w && data->inputs.key_d)
		return (vec_rotate_to(speed, M_PI_4), 1);
	else if (data->inputs.key_d && data->inputs.key_s)
		return (vec_rotate_to(speed, M_PI * 0.75), 1);
	else if (data->inputs.key_s && data->inputs.key_a)
		return (vec_rotate_to(speed, M_PI * -0.75), 1);
	else if (data->inputs.key_w && data->inputs.key_a)
		return (vec_rotate_to(speed, -M_PI_4), 1);
	return (0);
}

int	one_key(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w)
		return (1);
	else if (data->inputs.key_a)
		return (vec_rotate_to(speed, -M_PI_2), 1);
	else if (data->inputs.key_s)
		return (vec_rotate_to(speed, -M_PI), 1);
	else if (data->inputs.key_d)
		return (vec_rotate_to(speed, M_PI_2), 1);
	return (0);
}
