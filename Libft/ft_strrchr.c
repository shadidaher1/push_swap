/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:44:11 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 12:01:19 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<string.h>
// #include<stdio.h>
// size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;
	int		cond;

	cond = 0;
	last = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			last = i;
			cond = 1;
		}
		i++;
	}
	if (cond)
		return ((char *)(s + last));
	else if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
// int main ()
// {
// 	const char a[]="Weelcomonee";
// 	int b = 'o';
// 	char *d= strrchr(a,b);
// 	char *c = ft_strrchr(a,b);
// 	printf("%s\n",d);
// 	printf("%s",c);
// }