/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:26:36 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 12:13:39 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// #include<stdio.h>

static size_t	count_digits(long long n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (1);
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		count;
	char		*arr;
	long long	i;

	i = n;
	count = count_digits(n);
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	arr = malloc(sizeof (char) * (count +1));
	arr[count] = '\0';
	while (count--)
	{
		arr[count] = i % 10 + '0';
		i /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
// int main()
// {
//     int n = -1233;
// 	int	i = 0;
// 	char *a = ft_itoa(n);
// 		printf("%s\n", a);
// 	while(a[i])
// 	{
// 		printf("%c\n", a[i]);
// 		i++;
// 	}
// }