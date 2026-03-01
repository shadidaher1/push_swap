#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(t_stack *stack)
{
	int	temp;
	int	ind_tmp;

	if (stack->size >= 2)
	{
		temp = stack->head->number;
		stack->head->number = stack->head->next->number;
		stack->head->next->number = temp;
		ind_tmp = stack->head->index;
		stack->head->index = stack->head->next->index;
		stack->head->next->index = ind_tmp;
	}
}

void	sa(t_stack *stack, t_stats *stats)
{
	swap(stack);
	write(1, "sa\n", 3);
	if (stats)
	{
		stats->sa++;
		stats->total_ops++;
	}
}

void	sb(t_stack *stack, t_stats *stats )
{
	swap(stack);
	write(1, "sb\n", 3);
	if (stats)
	{
		stats->sb++;
		stats->total_ops++;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	if (stats)
	{
		stats->ss++;
		stats->total_ops++;
	}
}
