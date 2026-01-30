/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:46:47 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/05 13:02:22 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return ;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int main()
// {
// 	char a[] = "abcdfef";
// 	char b[] = "abcdfef";
// 	ft_bzero(a,1);
// 	printf("%s\n",a);
// 	bzero(b,1);
// 	printf("%s\n",b);
// }