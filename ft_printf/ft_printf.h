/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:28:42 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/12 12:47:07 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_char(char c);
int	ft_printf_string(char *str);
int	ft_printf_decimal(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hex_low(unsigned int n);
int	ft_printf_hex_cap(unsigned int n);
int	ft_printf_pointer(void *ptr);

#endif