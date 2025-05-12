/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:02:20 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/12 12:21:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "settings.h"
#include "colors.h"

void	put_help(void)
{
	static char	*texts[10] = {
		"Controls:",
		"move with WASD and MOUSE",
		"left_arrow : look left",
		"right_arrow : look right",
		"+/- : minimap zoom",
		"g : toggle minimap grid",
		"r : toggle minimap rotation",
		"c : toggle minimap rays",
		"t : toggle minimap target",
		"e : open/close doors"
	};
	int			index;

	index = 0;
	while (index < 10)
	{
		mlx_put_string(g_mlx, texts[index], 20, MAX_MINIMAP_SIZE + 2 * \
			MINIMAP_MARGIN + index * 20);
		index++;
	}
}
