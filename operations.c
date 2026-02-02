#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void swap(t_stack *stack)
{
    int temp;
    int ind_tmp;

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
void sa(t_stack *stack)
{
    swap(stack);
    write(1, "sa\n", 3);
}

void sb(t_stack *stack)
{
    swap(stack);
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}

static void push(t_stack *dst, t_stack *src)
{
    t_node *tmp;

    if (!src || !src->head)
        return;
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
void pa(t_stack *a, t_stack *b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    push(b, a);
    write(1, "pb\n", 3);
}

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if (!stack || stack->size < 2)
        return;
    first = stack->head;
    last = stack->tail;
    stack->head = stack->head->next;
    stack->head->prev = NULL;
    last->next = first;
    first->prev = stack->tail;
    first->next = NULL;
    stack->tail = first;
}

void ra(t_stack *stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr/n", 3);
}
static void revers_rotate(t_stack *stack)
{
    t_node *last;
    t_node *first;

    if (!stack || stack->size < 2)
        return;
    first = stack->head;
    last = stack->tail->prev;
    stack->head = stack->tail;
    stack->head->prev = NULL;
    first->prev = stack->head;
    stack->head->next = first;
    last->next = NULL;
    stack->tail = last;
}
void rra(t_stack *stack)
{
    revers_rotate(stack);
    write(1, "rra\n", 4);
}
void rrb(t_stack *stack)
{
    revers_rotate(stack);
    write(1, "rrb\n", 4);
}
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    revers_rotate(stack_a);
    revers_rotate(stack_b);
    write(1, "rrr\n", 4);
}