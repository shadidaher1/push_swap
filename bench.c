#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include "Libft/libft.h"


void    print_disorder_pct(float disorder, int fd)
{
    int    integer_part;
    int    decimal_part;
    float  scaled;

    scaled = disorder * 100;
    integer_part = (int)scaled;
    // Get two decimal places
    decimal_part = (int)((scaled - integer_part) * 100);
    if (decimal_part < 0)
        decimal_part *= -1;
    
    ft_putnbr_fd(integer_part, fd);
    ft_putchar_fd('.', fd);
    if (decimal_part < 10)
        ft_putchar_fd('0', fd);
    ft_putnbr_fd(decimal_part, fd);
    ft_putstr_fd("%\n", fd);
}

void print_bench(t_stats *stats, char *strategy)
{
    ft_putstr_fd("Disorder: ", 2);
    print_disorder_pct(stats->disorder, 2); 
    ft_putstr_fd("Strategy: ", 2);
    ft_putendl_fd(strategy, 2);
    ft_putstr_fd("Total operations: ", 2);
    ft_putnbr_fd(stats->total_ops, 2);
    ft_putstr_fd("\n", 2);
}