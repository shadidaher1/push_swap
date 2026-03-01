#include "push_swap.h"
#include <stdio.h>
#include "../Libft/libft.h"

void	print_st(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	run_push_swap(int argc, char **argv, t_stats *stats)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*strategy;
	int		start;

	start = parse_flags(argc, argv, &strategy, stats);
	if (start == argc)
		return ;
	is_number(argc, argv, start);
	create_stack(&stack_a, start, argc, argv);
	init_stack(&stack_b);
	assgin_indices(&stack_a);
	stats->disorder = calculate_disorder(&stack_a);
	if (ft_strncmp(strategy, "simple", 7) == 0)
		simple_sort(&stack_a, &stack_b, stats);
	else if (ft_strncmp(strategy, "medium", 7) == 0)
		medium_sort(&stack_a, &stack_b, stats);
	else if (ft_strncmp(strategy, "complex", 8) == 0)
		radix_sort(&stack_a, &stack_b, stats);
	else
		adaptive_sort(&stack_a, &stack_b, stats);
	if (stats->bench_mode)
		print_bench(stats, get_strategy_name(strategy, stats->disorder));
	free_stack(&stack_a);
	// print_St(&stack_a);
}

int	main(int argc, char **argv)
{
	t_stats	stats;

	ft_memset(&stats, 0, sizeof(t_stats));
	run_push_swap(argc, argv, &stats);
	return (0);
}
