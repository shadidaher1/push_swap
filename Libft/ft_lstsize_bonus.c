/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:56:20 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/09 18:22:24 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main ()
// {
// 	t_list	*lst =ft_lstnew("hello");
// 	t_list *new = ft_lstnew("shadi");
// 	t_list *one = ft_lstnew("sdi");
// 	ft_lstadd_front(&lst, new);
// 	ft_lstadd_front(&lst,one);
// 	printf("%d",ft_lstsize(lst));
// }