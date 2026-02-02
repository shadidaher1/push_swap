#include "push_swap.h"
#include <stdio.h>

static void sort_two(t_stack *stack_a)
{
    if (stack_a->head->number > stack_a->head->next->number)
        sa(stack_a);
}
int get_min_pos(t_stack *stack)
{
    t_node *curr;
    int min_pos;
    int min_val;
    int pos;

    pos = 0;
    if (!stack || !stack->head)
        return (-1);
    curr = stack->head;
    min_pos = 0;
    min_val = stack->head->number;
    while (curr)
    {
        if (curr->number < min_val)
        {
            min_val = curr->number;
            min_pos = pos;
        }
        pos++;
        curr = curr->next;
    }
    return (min_pos);
}

static void sort_three(t_stack *stack_a)
{
    int pos;
    t_node *tmp;

    tmp = stack_a->head->next;

    pos = get_min_pos(stack_a);

    if (pos == 1 && stack_a->head->number < tmp->next->number)
        sa(stack_a);
    else if (stack_a->head->number > tmp->next->number && pos == 1)
    {
        ra(stack_a);
    }
    else if (tmp->number > tmp->next->number && pos == 0)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (pos == 2 && stack_a->head->number > tmp->number)
    {
        ra(stack_a);
        sa(stack_a);
    }
    else if (pos == 2 && stack_a->head->number < tmp->number)
        rra(stack_a);
}

static void empty_stackb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b)
        return;
    else
    {
        while (stack_b->head != NULL)
        {
            pa(stack_a, stack_b);
        }
    }
}
int is_sorted(t_stack *stack_a)
{
    t_node *tmp;

    if (stack_a->size <= 1 || !stack_a || !stack_a->head)
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

void sort_list(t_stack *stack_a, t_stack *stack_b)
{
    int pos;

    if (is_sorted(stack_a))
        return;
    if (stack_a->size == 2)
        return (sort_two(stack_a));
    else if (stack_a->size == 3)
        return (sort_three(stack_a));
    pos = get_min_pos(stack_a);
    while (stack_a->size > 3)
    {
        pos = get_min_pos(stack_a);
        while (pos != 0)
        {
            if (pos <= stack_a->size / 2)
                ra(stack_a);
            else if (pos > stack_a->size / 2)
                rra(stack_a);
            pos = get_min_pos(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    empty_stackb(stack_a, stack_b);
}
