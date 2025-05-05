/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:37 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 12:13:00 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"
#include "collision_detection.h"
#include "rect.h"
#include "render.h"

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
	t_vec2		speed;
	t_vec2		new_position;
	int			x;
	int			y;
	t_collision	collision;

	speed = vec_multiply_n(data->player.dir, PLAYER_ACCELERATION * mlx->delta_time);
	if (four_keys(data) || three_keys(data, &speed) || two_keys(data, &speed) || one_key(data, &speed))
	{
		vec_add_to(&data->player.speed, &speed);
	}

	// Decelerate the speed
	vec_multiply_n_to(&data->player.speed, PLAYER_SPEED_DECREASE_MULTIPLIER);

	// Add the speed to the player
	new_position = vec_add(data->player.pos, data->player.speed);
	x = (int)new_position.x - 1;
	while (x < (int)new_position.x + 3)
	{
		y = (int)new_position.y - 1;
		while (y < (int)new_position.y + 3)
		{
			// Collision detection
			if (data->map.tiles[y][x].tile_type == TILE_WALL)
			{
				// printf("We are close to a wall %d;%d\n", x, y);

				t_rect tile = rect_from_point(vec_new(x * MINIMAP_SCALE, y * MINIMAP_SCALE), MINIMAP_SCALE, MINIMAP_SCALE);
				t_circle player = (t_circle) { vec_add_n(vec_multiply_n(new_position, MINIMAP_SCALE), PLAYER_SIZE / 2 * MINIMAP_SCALE), PLAYER_SIZE / 2 * MINIMAP_SCALE };

				put_rect(data->img, &tile, 0xFF0000FF);
				put_circle(data->img, player.pos, player.radius, 0x00FF00FF);
	
				collision = circle_collides_rect(&player, &tile);

				if (collision.colliding)
				{
					// printf("We have collision!\n");
					t_vec2 position_correction = vec_multiply_n(collision.dir, collision.amount / MINIMAP_SCALE);
					vec_add_to(&new_position, &position_correction);
					vec_add_to(&data->player.speed, &position_correction);
				}
				// else
				// {
				// 	printf("Rect does not collide with player:\n");
				// 	printf("Rect from %f;%f\n", tile.vertices[0].x, tile.vertices[0].y);
				// 	printf("Player at %f;%f\n", player.pos.x, player.pos.y);
				// }
			}
			y++;
		}
		x++;
	}
	//vec_add_to(&data->player.pos, &data->player.speed);
	data->player.pos = new_position;

	// Rotate the view direction
	if (data->inputs.key_left)
		vec_rotate_to(&data->player.dir, -PLAYER_ROTATION_SPEED * 10);
	else if (data->inputs.key_right)
		vec_rotate_to(&data->player.dir, PLAYER_ROTATION_SPEED * 10);
}
