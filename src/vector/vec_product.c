/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:05:35 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/02 00:14:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_cross_product(t_vec2 *vec1, t_vec2 *vec2)
{
	return (vec1->x * vec2->y - vec1->y * vec2->x);
}

double	vec_dot_product(t_vec2 *vec1, t_vec2 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y);
}
