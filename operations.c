#include "push_swap.h"
#include <stdlib.h>

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
        write(1, "sa\n", 3);
    }
}
void sa(t_stack *stack)
{
    swap(stack);
    write(1,"sa\n",3);
}

void sb(t_stack *stack)
{
    swap(stack);
    write(1,"sb\n",3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1,"ss\n",3);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp;
    // t_node tmp_b;
    if (!stack_b)
        return ;
    tmp = stack_b->head;
    tmp->next = stack_a->head->next;

    stack_a->head = tmp;
}
