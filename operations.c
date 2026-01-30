#include "push_swap.h"

void sa(t_stack *stack)
{
    t_node *temp;
    t_node *ind_tmp;

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
