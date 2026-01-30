/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:56:17 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/05 11:38:49 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<ctype.h>
// #include<stdio.h>
#include"libft.h"

int	ft_tolower(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a >= 'A' && a <= 'Z')
		a += 32;
	return (a);
}
// int main()
// {
// 	int a ='a';
// 	printf("%c",ft_tolower(a));
// }