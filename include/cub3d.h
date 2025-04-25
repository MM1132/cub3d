/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:27:55 by joklein           #+#    #+#             */
/*   Updated: 2025/04/24 18:23:45 by joklein          ###   ########.fr       */
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
extern int		map_value;

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
	TILE_FLOOR,
	TILE_WALL,
	TILE_SPACE,
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
}			t_data;

// returns 1 when the map is invalid, and 0 when it is valid
int				map_validation(char **argv, t_data *data);
// returns 1 when the character is a whitespace
int				white_space(char *str, int i);
// Returns the index of the first non-whitespace character in the string,
// starting from the given index i. Skips whitespace.
int				white_space_skip(char *str, int i);
// Create the map and return 0 if the map is valide
int				create_map(char *file, char *line, t_data *data);
// free split
void			free_split(char **split);
// write error massage, return 1
int err_mssg();
// frees the map
void	gc_free_map(t_data *data);
// read the map and create a file
char	*read_file(char **argv);
// get_next_line from file with gc
char *safe_gnl(char *file);
void		init_data(t_data *data);
void		render_minimap(t_data *data);
void		put_rect(mlx_image_t *img, t_rect *rect, uint32_t color);

// Hooks
void		loop_key_hook(void *param);

#endif
