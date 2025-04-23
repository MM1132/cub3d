/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:18:31 by joklein           #+#    #+#             */
/*   Updated: 2025/04/23 17:53:57 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "garbage_collector.h"

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

// char **add_gcsplit(char **str)
// {
// 	int i;
// 	char **dst;

// 	i = 0;
// 	while(str[i])
// 		i++;
// 	dst = gc_malloc((i + 1) * sizeof(void *));
// 	i = 0;
// 	while(str[i])
// 	{
// 		dst[i] = str[i];
// 		free(str[i++]);
// 	}
// 	free(str);
// 	return(dst);
// }

// void	free_split(char **split)
// {
// 	int i = 0;
// 	while (split && split[i])
// 		free(split[i++]);
// 	free(split);
// }

int err_mssg()
{
	write(2, "Error: invalid map\n", 21);
	return(1);
}
