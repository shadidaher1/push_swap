/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:01:18 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/09 18:46:56 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

// int main ()
// {
// 	t_list	*lst= ft_lstnew("42Breirut");

// 	t_list *new = ft_lstnew("shadi");
// 	t_list *one = ft_lstnew("sdi");
// 	ft_lstadd_front(&lst, new);
// 	ft_lstadd_front(&lst,one);
// 	t_list *last = ft_lstlast(lst);
// 	printf("%s",(char *)last->content);
// }
