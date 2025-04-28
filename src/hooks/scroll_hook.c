/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:53:27 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 18:59:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void	scroll_hook(double xdelta, double ydelta, void* param)
{
	t_data	*data;

	printf("You scrolled\n");
	(void)xdelta;
	(void)ydelta;
	data = (t_data *)param;
}
