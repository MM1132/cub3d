/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:37 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 19:47:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "collision_detection.h"
#include "rect.h"
#include "render.h"
#include "math.h"

static void	correct_player_position( \
	int x, \
	int y, \
	t_vec2 *new_position, \
	t_data *data)
{
	t_collision	collision;
	t_rect		tile;
	t_circle	player;
	t_vec2		position_correction;

	tile = rect_from_point(vec_new(x, y), 1, 1);
	player = (t_circle){vec_add_n(*new_position, PLAYER_SIZE / 2), \
		PLAYER_SIZE / 2};
	collision = circle_collides_rect(&player, &tile);
	if (collision.colliding)
	{
		position_correction = vec_multiply_n(collision.dir, collision.amount);
		vec_add_to(new_position, &position_correction);
		vec_add_to(&data->player.speed, &position_correction);
	}
}

static t_vec2	collide_player(t_data *data)
{
	t_vec2		new_position;
	int			x;
	int			y;

	new_position = vec_add(data->player.pos, data->player.speed);
	x = (int)new_position.x - 2;
	while (++x < (int)new_position.x + 3)
	{
		y = (int)new_position.y - 2;
		while (++y < (int)new_position.y + 3)
		{
			if (within_map_bounds(&data->map, x, y) && \
				data->map.tiles[y][x].tile_type == TILE_WALL)
			{
				correct_player_position(x, y, &new_position, data);
			}
		}
	}
	return (new_position);
}

void	player_update(t_data *data)
{
	t_vec2		speed;

	speed = vec_multiply_n(data->player.dir, \
		PLAYER_ACCELERATION * mlx->delta_time);
	if (four_keys(data) || three_keys(data, &speed) || \
		two_keys(data, &speed) || one_key(data, &speed))
		vec_add_to(&data->player.speed, &speed);
	vec_multiply_n_to(&data->player.speed, PLAYER_SPEED_DECREASE_MULTIPLIER);
	data->player.pos = collide_player(data);
	if (data->inputs.key_left)
		vec_rotate_to(&data->player.dir, PLAYER_ROTATION_SPEED * -10);
	else if (data->inputs.key_right)
		vec_rotate_to(&data->player.dir, PLAYER_ROTATION_SPEED * 10);
}
