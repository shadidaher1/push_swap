/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:39:48 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/03 12:08:07 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<string.h>
// #include<stdio.h>
#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*m_dest;
	const unsigned char		*m_src;

	m_dest = (unsigned char *)dest;
	m_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		m_dest[i] = m_src[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	 char src[]="shadi";
// 	char dest[]="daher";
// 	char m_dest[]="daher";
// 	ft_memcpy(dest,src,1);
// 	memcpy(m_dest,src,1);
// 	printf("%s\n",dest);
// 	printf("%s",m_dest);
// }
