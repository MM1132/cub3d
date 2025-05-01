/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:37 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 17:52:19 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

static int	four_keys(t_data *data)
{
	if (data->inputs.key_w &&data->inputs.key_a && data->inputs.key_s && \
		data->inputs.key_d)
	{
		return (1);
	}
	return (0);
}

static int	three_keys(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w && data->inputs.key_a && data->inputs.key_d)
		return (1);
	else if (data->inputs.key_a && data->inputs.key_w && data->inputs.key_s)
		return (vec_rotate_to(speed, PI * -0.5), 1);
	else if (data->inputs.key_s && data->inputs.key_a && data->inputs.key_d)
		return (vec_rotate_to(speed, PI * -1), 1);
	else if (data->inputs.key_d && data->inputs.key_w && data->inputs.key_s)
		return (vec_rotate_to(speed, PI * 0.5), 1);
	return (0);
}

static int	two_keys(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w && data->inputs.key_s)
		return (1);
	else if (data->inputs.key_a && data->inputs.key_d)
		return (vec_rotate_to(speed, PI * -0.5), 1);
	else if (data->inputs.key_w && data->inputs.key_d)
		return (vec_rotate_to(speed, PI * 0.25), 1);
	else if (data->inputs.key_d && data->inputs.key_s)
		return (vec_rotate_to(speed, PI * 0.75), 1);
	else if (data->inputs.key_s && data->inputs.key_a)
		return (vec_rotate_to(speed, PI * -0.75), 1);
	else if (data->inputs.key_w && data->inputs.key_a)
		return (vec_rotate_to(speed, PI * -0.25), 1);
	return (0);
}

static int	one_key(t_data *data, t_vec2 *speed)
{
	if (data->inputs.key_w)
		return (1);
	else if (data->inputs.key_a)
		return (vec_rotate_to(speed, PI * -0.5), 1);
	else if (data->inputs.key_s)
		return (vec_rotate_to(speed, PI * -1), 1);
	else if (data->inputs.key_d)
		return (vec_rotate_to(speed, PI * 0.5), 1);
	return (0);
}

void	player_update(t_data *data)
{
	t_vec2	speed;

	speed = vec_multiply_n(data->player.dir, PLAYER_ACCELERATION * mlx->delta_time);
	if (four_keys(data) || three_keys(data, &speed) || two_keys(data, &speed) || one_key(data, &speed))
	{
		vec_add_to(&data->player.speed, &speed);
	}

	// Decelerate the speed
	vec_multiply_n_to(&data->player.speed, PLAYER_SPEED_DECREASE_MULTIPLIER);

	// Add the speed to the player
	vec_add_to(&data->player.pos, &data->player.speed);

	// Rotate the view direction
	if (data->inputs.key_left)
		vec_rotate_to(&data->player.dir, -PLAYER_ROTATION_SPEED * 10);
	else if (data->inputs.key_right)
		vec_rotate_to(&data->player.dir, PLAYER_ROTATION_SPEED * 10);
}
