/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:14:04 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/03 11:45:31 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include <ctype.h>
#include"libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')))
		return (1);
	return (0);
}

// int main ()
// {
// 	int a = 98;
// 	printf("%d\n",ft_isalnum(a));
// 	printf("%d",isalnum(a));
// }