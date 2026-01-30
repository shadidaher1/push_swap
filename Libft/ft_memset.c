/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:18:37 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/03 13:59:41 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include <string.h>
#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*a ;
	unsigned char		r ;

	i = 0;
	a = (unsigned char *)s;
	r = (unsigned char)c;
	while (i < n)
	{
		a[i] = r;
		i++;
	}
	return (s);
}
// int main()
// {
// 	char	a[] = "12345";
// 	char 	b[] = "12345";
// 	ft_memset(a,'a',2);
// 	memset(b,'a',2);
// 	printf("%s \n",a);
// 	printf("%s",b);
// }