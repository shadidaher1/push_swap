/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:03 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/03 14:55:34 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<ctype.h>
// #include<stdio.h>
#include"libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a >= 'a' && a <= 'z')
		a -= 32;
	return (a);
}
// int main()
// {
// 	int a ='a';
// 	printf("%c",ft_toupper(a));
// }