/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:31 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:37:58 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_char(char c);
int	ft_printf_string(char *str);
int	ft_printf_decimal(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hex_low(unsigned int n);
int	ft_printf_hex_cap(unsigned int n);
int	ft_printf_pointer(void *ptr);

int	check(va_list lst, char str)
{
	int	i;

	i = 0;
	if (str == 'c')
		i = ft_printf_char((char)va_arg(lst, int));
	if (str == 's')
		i = ft_printf_string(va_arg(lst, char *));
	if (str == 'd' || str == 'i')
		i = ft_printf_decimal(va_arg(lst, int));
	if (str == 'u')
		i = ft_printf_unsigned(va_arg(lst, unsigned int));
	if (str == 'x')
		i = ft_printf_hex_low(va_arg(lst, unsigned int));
	if (str == 'X')
		i = ft_printf_hex_cap(va_arg(lst, unsigned int));
	if (str == 'p')
		i = ft_printf_pointer(va_arg(lst, void *));
	return (i);
}

int	check_0(char str)
{
	if (str == 'c' || str == 's' || str == 'p'
		|| str == 'd' || str == 'i' || str == 'u'
		|| str == 'x' || str == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;

	va_start(lst, str);
	if (!str)
		return (-1);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (check_0(str[i]))
				len += check(lst, str[i]);
			else if (str[i] == '%')
				len += ft_printf_char('%');
		}
		else
			len += ft_printf_char(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
// int main(void)
// {
// printf("%d\n", ft_printf("hello sh%sdi", "aaa"));
// printf("%d\n", printf("hello sh%sdi", "aaa"));
// printf("%d\n", ft_printf("1 + 1 = %d", -1235));
// printf("%d\n", printf("1 + 1 = %d", -2147483648));
// ft_printf("%u\n", 4294967295);
// ft_printf("%u\n", 4294967295);
// ft_printf("173 i  hex is %X\n", 4294967295);
// printf("173 i  hex is %X", 4294967295U);
// int *x = NULL;
// printf("%p\n", x);
// ft_printf_pointer(&x);
// }