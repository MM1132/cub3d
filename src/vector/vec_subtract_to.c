/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_subtract_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:23:27 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/07 15:37:56 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_subtract_to(t_vec2 *first, t_vec2 *second)
{
	first->x -= second->x;
	first->y -= second->y;
}

void	vec_subtract_n_to(t_vec2 *vec, double n)
{
	vec->x -= n;
	vec->y -= n;
}
