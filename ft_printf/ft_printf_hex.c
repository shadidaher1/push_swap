/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:20 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:44:15 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c);

static int	count_hex_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_printf_hex_cap(unsigned int n)
{
	char	*base;
	int		count;

	count = count_hex_digits(n);
	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_printf_hex_cap(n / 16);
	ft_printf_char(base[n % 16]);
	return (count);
}

int	ft_printf_hex_low(unsigned int n)
{
	char	*base;
	int		count;

	count = count_hex_digits(n);
	base = "0123456789abcdef";
	if (n >= 16)
		ft_printf_hex_low(n / 16);
	ft_printf_char(base[n % 16]);
	return (count);
}
