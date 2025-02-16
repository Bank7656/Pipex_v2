/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:18 by thacharo          #+#    #+#             */
/*   Updated: 2024/09/04 19:27:24 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&new_list, ft_lstnew(f(lst -> content)));
		if (new_list == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (new_list);
}
