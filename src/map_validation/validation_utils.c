/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:18:31 by joklein           #+#    #+#             */
/*   Updated: 2025/04/28 15:45:57 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	white_space_skip(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	white_space(char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\t')
		return (1);
	return (0);
}
int err_mssg()
{
	write(2, "Error: invalid map\n", 20);
	return(1);
}
