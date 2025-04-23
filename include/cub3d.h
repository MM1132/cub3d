/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:27:55 by joklein           #+#    #+#             */
/*   Updated: 2025/04/23 16:59:04 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

extern mlx_t	*mlx;
extern int		map_value;

typedef struct s_data
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char		***map;
	// size_t		x;
	// int			y;
	// int			end;
}				t_data;

// returns 1 when the map is invalid, and 0 when it is valid
int				map_validation(char **argv, t_data *data);
// returns 1 when the character is a whitespace
int				white_space(char *str, int i);
// Returns the index of the first non-whitespace character in the string,
// starting from the given index i. Skips whitespace.
int				white_space_skip(char *str, int i);
// Create the map and return 0 if the map is valide
int				creat_map(int fd, char *line, t_data *data);
// free split
void			free_split(char **split);
// write error massage, return 1
int err_mssg();
#endif
