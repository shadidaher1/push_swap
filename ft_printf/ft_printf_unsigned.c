/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:28 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:46:38 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c);

static int	count_digits(unsigned int n)
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

int	ft_printf_unsigned(unsigned int n)
{
	int	count;

	count = count_digits(n);
	if (n >= 10)
		ft_printf_unsigned(n / 10);
	ft_printf_char(n % 10 + '0');
	return (count);
}

// int main(void)
// {
// printf("%d\n", ft_printf_unsigned(-1));
// }