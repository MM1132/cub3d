/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:49:32 by joklein           #+#    #+#             */
/*   Updated: 2025/05/12 12:25:04 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include "libft.h"

static void	add_to_gc(char **split)
{
	int		i;
	size_t	size;

	i = 0;
	while (split[i])
	{
		size = (ft_strlen(split[i]) + 1) * sizeof(char);
		gc_add(split[i], size);
		i++;
	}
	size = sizeof(char **);
	gc_add(split, size);
}

char	**safe_split(char *str, char c)
{
	char	**split_stuff;

	split_stuff = ft_split(str, c);
	add_to_gc(split_stuff);
	return (split_stuff);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		gc_free(split[i]);
		i++;
	}
	gc_free(split);
}
