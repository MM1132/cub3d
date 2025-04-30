/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:27:55 by joklein           #+#    #+#             */
/*   Updated: 2025/04/30 19:43:50 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "vector.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

extern mlx_t	*mlx;
extern int		map_value;

typedef struct s_ray
{
	t_vec2	start_pos;
	t_vec2	angle;
	t_vec2  next_dis;
	t_vec2	last_dis_pos;
	t_vec2	next_tile;
	double	length;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	speed;
	t_vec2	dir;
}	t_player;

#define NUMBER_OF_TILES 3
typedef enum s_tile_type
{
	TILE_FLOOR,
	TILE_WALL,
	TILE_SPACE,
	//TILE_DOOR,
}	t_tile_type;

typedef struct s_tile
{
	t_tile_type	tile_type;
	float		state; // For example, determining how much open a door is
}	t_tile;

typedef struct s_map
{
	t_tile		**tiles;
	size_t		width;
	size_t		height;
}	t_map;

typedef struct s_inputs
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_right;
	bool	key_left;
	t_vec2	mouse_pos;
	bool	toggle_minimap_grid;
	bool	toggle_minimap_rotation;
}	t_inputs;

typedef struct s_data
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_map		map;
	t_ray		*ray;
	t_player	player;
	mlx_image_t	*img;
	mlx_image_t	*minimap_img;
	t_inputs	inputs;
}			t_data;

// INITIALIZATION
void		init_inputs(t_inputs *down_keys);
void		init_player(t_player *player);
void		init_data(t_data *data);

// MAP VALIDATAION
// set width and height of the map
void	    set_width_height(char *file, t_data *data, int i);
// returns 1 when the map is invalid, and 0 when it is valid
int			map_validation(char **argv, t_data *data);
// returns 1 when the character is a whitespace
int			white_space(char *str, int i);
// Returns the index of the first non-whitespace character in the string,
// starting from the given index i. Skips whitespace.
int			white_space_skip(char *str, int i);
// Create the map and return 0 if the map is valid
int			create_map(char *file, char *line, t_data *data);
// free split
void		free_split(char **split);
// write error massage, return 1
int			err_mssg();
// frees the map
void		gc_free_map(t_data *data);
// read the map and create a file
char		*read_file(char **argv);
// get_next_line from file with gc
char 		*safe_gnl(char *file);
// find the start of the map
int			find_map_start(char *file);
// like atoi: it changes 'a' to tile_type
t_tile_type	ft_atott(char c);
//checks if the zeros in the map are enclosed by ones
int			zeros_enclosed(t_data *data);
t_vec2		vec_add_value(t_vec2 vec, double value);
void		first_dis_calc(t_data *data, int32_t	rn);
void		render_world(t_data *data);

t_vec2		pos_to_minimap(t_vec2 pos);

// HOOKS
void		main_loop_hook(void *param);
void		cursor_hook(double xpos, double ypos, void* param);
void		scroll_hook(double xdelta, double ydelta, void* param);
void		key_hook(mlx_key_data_t keydata, void* param);
void 		resize_hook(int32_t width, int32_t height, void* param);

// UPDATING STUFF
void		update_player(t_data *data);

#endif
