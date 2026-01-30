#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    // t_stack stack_b;

    is_number(argc, argv);
    init_stack(stack_a);
    create_stack(stack_a,argc, argv);
    printf("%d",stack_a->head->number);
    while (stack_a->head->next)
    {
        printf("%d",stack_a->head->next->number);

    }
}