/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:18 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:42:19 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c);

static int	count_digits(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_printf_decimal(int n)
{
	int			count;
	long long	num;

	num = n;
	count = count_digits(num);
	if (n < 0)
	{
		ft_printf_char('-');
		count++;
		num *= -1;
	}
	if (num >= 10)
		ft_printf_decimal(num / 10);
	ft_printf_char(num % 10 + '0');
	return (count);
}

// int main(void)
// {
// 	ft_printf_decimal(12);
// 	printf("\n");
// 	printf("%d\n", ft_printf_decimal(12));
// }