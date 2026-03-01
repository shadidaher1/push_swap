#include "push_swap.h"

static void	revers_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	last = stack->tail->prev;
	stack->head = stack->tail;
	stack->head->prev = NULL;
	first->prev = stack->head;
	stack->head->next = first;
	last->next = NULL;
	stack->tail = last;
}

void	rra(t_stack *stack, t_stats *stats)
{
	revers_rotate(stack);
	write(1, "rra\n", 4);
	if (stats)
	{
		stats->rra++;
		stats->total_ops++;
	}
}

void	rrb(t_stack *stack, t_stats *stats)
{
	revers_rotate(stack);
	write(1, "rrb\n", 4);
	if (stats)
	{
		stats->rrb++;
		stats->total_ops++;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	revers_rotate(stack_a);
	revers_rotate(stack_b);
	write(1, "rrr\n", 4);
	if (stats)
	{
		stats->rrr++;
		stats->total_ops++;
	}
}
