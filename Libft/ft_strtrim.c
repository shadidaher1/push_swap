/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:32:09 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 12:01:37 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

// char	*ft_strchr(const char *s, int c);
// char	*ft_strrchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
		trim = malloc(1);
		if (!trim)
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strrchr(set, s1[j - 1]))
	{
		j--;
	}
	trim = malloc(sizeof(char) * j - i + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + i, j - i + 1);
	return (trim);
}
// int main()
// {
//     char s1[] = "abcShadi Daheracbs";
//     char s2[] = "cba";
//     printf("%s\n", ft_strtrim(s1, s2));
// }
