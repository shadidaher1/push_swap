#include "push_swap.h"
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"

static void	print_disorder(t_stats *stats)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(stats->disorder * 100);
	dec_part = (int)(stats->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putstr_fd(".", 2);
	if (dec_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_ops(t_stats *stats)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(stats->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(stats->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(stats->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(stats->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(stats->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_stats *stats, char *strategy)
{
	print_disorder(stats);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(stats->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops(stats);
}

char	*get_strategy_name(char *strategy, float disorder)
{
	if (ft_strncmp(strategy, "simple", 7) == 0)
		return ("Simple / O(n^2)");
	if (ft_strncmp(strategy, "medium", 7) == 0)
		return ("Medium / O(nsqrtn)");
	if (ft_strncmp(strategy, "complex", 8) == 0)
		return ("Complex / O(nlogn)");
	if (disorder < 0.2)
		return ("Adaptive / O(n)");
	if (disorder < 0.5)
		return ("Adaptive / O(nsqrtn)");
	return ("Adaptive / O(nlogn)");
}

int	is_sorted(t_stack *stack_a)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head || stack_a->size <= 1)
		return (1);
	tmp = stack_a->head;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
