/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:23 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:45:04 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c);

int	ft_printf_hex_low(unsigned int n);

static int	count_hex_digits(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	ft_printf_add(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = count_hex_digits(n);
	if (n >= 16)
		ft_printf_add(n / 16);
	ft_printf_char(base[n % 16]);
	return (count);
}

int	ft_printf_pointer(void *ptr)
{
	unsigned long	add;
	int				i;

	if (!ptr)
		return (ft_printf_string("(nil)"));
	add = (unsigned long)ptr;
	ft_printf_char('0');
	ft_printf_char('x');
	i = 2;
	i += ft_printf_add(add);
	return (i);
}
