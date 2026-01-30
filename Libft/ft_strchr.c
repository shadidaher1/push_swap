/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:32:23 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/05 11:41:46 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<string.h>
// #include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// int main ()
// {
// 	const char a[]="Weelcomne";
// 	int b = 'e';
// 	char *d= strchr(a,b);
// 	char *c = ft_strchr(a,b);
// 	printf("%s\n",d);
// 	printf("%s",c);
// }