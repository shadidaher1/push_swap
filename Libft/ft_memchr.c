/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:41:09 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/05 11:30:52 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	return (NULL);
}

// int main ()
// {
// 	const char a[]="Weelcomne";
// 	int b = '\0';
// 	char *d= memchr(a,b,4);
// 	char *c = ft_memchr(a,b,4);
// 	printf("%s\n",d);
// 	printf("%s",c);
// }