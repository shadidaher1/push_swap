/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:28:54 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 11:59:35 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>
// #include<bsd/string.h>
// size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int main ()
// {
// 	char dest[]= "shadi";
// 	char src[]= "daher";
// 	char mdest[]="shadi";
// 	printf("%zu",strlcpy(mdest,src,0));
// 	printf("%s\n",mdest);
// 	printf("%zu",ft_strlcpy(dest,src,0));
// 	printf("%s",dest);
// }