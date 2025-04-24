/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:27:55 by joklein           #+#    #+#             */
/*   Updated: 2025/04/24 16:45:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "settings.h"
# include "vector.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

extern mlx_t	*mlx;

typedef struct s_rect
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	height;
}	t_rect;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		speed_x;
	double		speed_y;
	t_vector2	dir;
}	t_player;

typedef enum s_tile_type
{
	TILE_SPACE,
	TILE_FLOOR,
	TILE_WALL,
	TILE_DOOR,
}	t_tile_type;

typedef struct s_tile
{
	t_tile_type	tile_type;
	float		state; // For example, determining how much open a door is
}	t_tile;

typedef struct s_map
{
	t_tile	**tiles;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_down_keys
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
}	t_down_keys;

typedef struct s_data
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_map		map;
	t_player	player; // TODO: Initialize the player data
	mlx_image_t	*img;
	t_down_keys	down_keys;
	// int			end; // TODO: Ask Jona what this is
}			t_data;

// returns 1 when the map is invalid, and 0 when it is valid
int			map_invalid(char **argv, t_data *data);

void		init_data(t_data *data);
void		render_minimap(t_data *data);
void		put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);

// Hooks
void		loop_key_hook(void *param);

#endif
