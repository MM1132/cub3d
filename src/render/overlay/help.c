/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:02:20 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 12:47:43 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	put_help(void)
{
	static char	*texts[7] = {
		"Controls:",
		"move with WASD and MOUSE",
		"left_arrow -> look left",
		"right_arrow -> look right",
		"g -> toggle minimap grid",
		"r -> toggle minimap rotation",
		"c -> toggle minimap rays"
	};
	int			index;

	index = 0;
	while (index < 7)
	{
		mlx_put_string(g_mlx, texts[index], 20, 420 + index * 20);
		index++;
	}
}
