#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || !src->head)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	if (dst->head)
		dst->head->prev = tmp;
	else
		dst->tail = tmp;
	tmp->prev = NULL;
	tmp->next = dst->head;
	dst->head = tmp;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, t_stats *stats)
{
	push(a, b);
	write(1, "pa\n", 3);
	if (stats)
	{
		stats->pa++;
		stats->total_ops++;
	}
}

void	pb(t_stack *a, t_stack *b, t_stats *stats)
{
	push(b, a);
	write(1, "pb\n", 3);
	if (stats)
	{
		stats->pb++;
		stats->total_ops++;
	}
}
