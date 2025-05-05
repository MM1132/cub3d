/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_swap_xy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:55:44 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 01:08:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_swap_xy(t_vec2	*vec)
{
	double	save_x;

	save_x = vec->x;
	vec->x = vec->y;
	vec->y = save_x;
}
