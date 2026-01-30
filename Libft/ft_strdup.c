/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:20:13 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 11:55:50 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include <string.h>
// #include <stdio.h>
// size_t	ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
// int main()
// {
// 	char s[]="abc";
// 	char	*a = ft_strdup(s);
// 	printf("%lu\n",ft_strlen(a));
// 	printf("%lu\n",ft_strlen(ft_strdup(s)));
// 	printf("%s\n",ft_strdup(s));
// 	printf("%s\n",strdup(s));
// }