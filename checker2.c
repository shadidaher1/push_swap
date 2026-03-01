#include "push_swap.h"
#include <limits.h>
#include "Libft/libft.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	check_duplicates(char **split, int start, int should_free)
{
	int	i;
	int	j;
	int	num;

	i = start;
	while (split[i])
	{
		num = ftt_atoi(split[i]);
		j = i + 1;
		while (split[j])
		{
			if (ftt_atoi(split[j]) == num)
			{
				if (should_free)
					free_split(split);
				throw_error();
			}
			j++;
		}
		i++;
	}
}

void	check_double(int argc, char **argv, int start)
{
	char	**split;

	if (start == argc -1)
	{
		split = ft_split(argv[start], ' ');
		check_duplicates(split, 0, 1);
		free_split(split);
	}
	else
		check_duplicates(argv, start, 0);
}

long	ftt_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
			throw_error();
		i++;
	}
	return (result * sign);
}
