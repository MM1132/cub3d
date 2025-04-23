/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:55:40 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/22 15:17:34 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveone(t_list **head, t_list *to_delete, void (*del)(void *))
{
	t_list	*current_element;
	t_list	*previous_element;

	previous_element = NULL;
	current_element = *head;
	while (current_element)
	{
		if (current_element == to_delete)
		{
			if (previous_element)
				previous_element->next = current_element->next;
			else
				*head = current_element->next;
			ft_lstdelone(to_delete, del);
			return ;
		}
		previous_element = current_element;
		current_element = current_element->next;
	}
}
