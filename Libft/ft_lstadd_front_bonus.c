/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:59:37 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/09 18:18:28 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main ()
// {
// 	t_list *lst = ft_lstnew("hellloooo");
// 	t_list *lst1 = ft_lstnew("marhaba");
// 	ft_lstadd_front(&lst1,lst);
// 	printf("%s ->",(char *) lst1->content);
// 	lst1 = lst1-> next;
// 	printf("%s",(char *) lst1->content);
// }
