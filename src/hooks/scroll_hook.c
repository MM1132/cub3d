/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:53:27 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/20 16:22:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	printf("You scrolled\n");
	(void)xdelta;
	(void)ydelta;
	data = (t_data *)param;
	(void)data;
}
