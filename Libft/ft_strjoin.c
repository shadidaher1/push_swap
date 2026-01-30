/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:34 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 11:59:19 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

// size_t	ft_strlen(const char *s);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 && !s2)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = malloc((len_s1 + len_s2 + 1) * sizeof (char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_s1 + len_s2 + 1);
	return (new);
}

// int main()
// {
// 	char s1[] = "1234";
// 	char s2[] = "56789";
// 	char *s3 = ft_strjoin(s1, s2);
// 	printf("%s\n", s3);
// }