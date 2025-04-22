/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:27:55 by joklein           #+#    #+#             */
/*   Updated: 2025/04/22 18:12:15 by joklein          ###   ########.fr       */
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

typedef struct s_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	// char		***map;
	// size_t		x;
	// int			y;
	// int			end;
}			t_data;

int			map_invalid(char **argv, t_data *data);

#endif
