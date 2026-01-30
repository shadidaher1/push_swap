/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:45:04 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/03 13:59:04 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	// size_t i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	// i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}

// int main ()
// {
// 	char src[20]="shadi";
// 	char	src1[20]="shadi";
// 	memmove(src ,src,4);
// 	printf("%s\n",src);
// 	ft_memmove(src1,src1,4);
// 	printf("%s\n",src1);
// }