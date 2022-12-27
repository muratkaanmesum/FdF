/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:45:32 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/11 15:48:11 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlist;

	new = ft_lstnew(f(lst->content));
	lst = lst->next;
	newlist = new;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			del(new->content);
		ft_lstadd_back(&newlist, new);
		lst = lst->next;
	}
	return (newlist);
}
