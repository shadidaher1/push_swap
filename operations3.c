#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	last = stack->tail;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	last->next = first;
	first->prev = stack->tail;
	first->next = NULL;
	stack->tail = first;
}

void	ra(t_stack *stack_a, t_stats *stats)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if (stats)
	{
		stats->ra++;
		stats->total_ops++;
	}
}

void	rb(t_stack *stack_b, t_stats *stats)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if (stats)
	{
		stats->rb++;
		stats->total_ops++;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if (stats)
	{
		stats->rr++;
		stats->total_ops++;
	}
}
