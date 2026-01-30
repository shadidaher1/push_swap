/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:28:29 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 11:47:23 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!content)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// int main()
// {
// 	char	*a= "abc";
// 	t_list	*node;
// 	node = ft_lstnew(a);
// 	printf("%s",(char *)node->content);
// }
