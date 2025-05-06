/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:57:48 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 13:56:27 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_hook(\
	mouse_key_t button, \
	action_t action, \
	modifier_key_t mods, \
	void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		data->inputs.mouse_locked = true;
}
