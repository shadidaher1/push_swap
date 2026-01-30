/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:03:59 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 11:59:30 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>
// #include<bsd/string.h>
// size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	j = dst_len;
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	else
	{
		i = 0;
		while (src[i] != '\0' && j < size -1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		return (src_len + dst_len);
	}
}
// int main ()
// {
// 	char dest[22]= "shadi";
// 	char src[]= "daaaher";
// 	char mdest[22]="shadi";
// 	size_t size = 20;
// 	printf("%zu",strlcat(mdest,src,size));
// 	printf("%s\n",mdest);
// 	printf("%zu",ft_strlcat(dest,src,size));
// 	printf("%s",dest);
// }