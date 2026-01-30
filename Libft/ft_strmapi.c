/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:31:52 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 12:00:30 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

// size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	while (i < size)
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

// int main ()
// {
// 	const char *c ="abcdef";
// 	printf("%s",ft_strmapi(c,f));
// }