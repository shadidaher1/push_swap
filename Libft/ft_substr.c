/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:51 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 12:02:07 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

// size_t	ft_strlen(const char *s);
// char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	s_len;
	size_t	i;
	size_t	size;

	i = 0;
	s_len = ft_strlen(s);
	size = s_len - start;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > size)
		len = size;
	subst = (char *)malloc ((len + 1) * sizeof(char));
	if (!subst)
		return (NULL);
	while (i < len && s[i])
	{
		subst[i] = s[start + i];
		i++;
	}
	subst[i] = '\0';
	return (subst);
}
// int main()
// {
// 	char *s = "hello welocme home";
// 	unsigned int start = 2;
// 	size_t len = 10;
// 	printf("%ld\n",ft_strlen(s));
// 	printf("%s", ft_substr(s, start, len));
// }
