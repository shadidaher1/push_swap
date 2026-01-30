/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:20 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 13:24:12 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static t_list	*add(t_list **new, void *content, void (*del)(void *))
{
	t_list	*copy;

	copy = ft_lstnew(content);
	if (!copy)
	{
		ft_lstclear(new, del);
		del(content);
		return (NULL);
	}
	ft_lstadd_back(new, copy);
	return (copy);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*cp;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cp = f(lst->content);
		if (!cp || !add(&new, cp, del))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
