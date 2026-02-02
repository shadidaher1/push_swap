#include "push_swap.h"
#include <stdio.h>

void print_St(t_stack *stack)
{
    t_node *current;

    current = stack->head; // ← Use a temp variable
    while (current)
    {
        printf("%d\n", current->number);
        current = current->next; // ← Move the temp, not stack->head!
    }
}
void print_head(t_stack *stack)
{
    printf("%d", stack->head->number);
}
int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    // int i;

    // int min;
    is_number(argc, argv);
    create_stack(&stack_a, argc, argv);
    init_stack(&stack_b);
    //     print_St(&stack_a);
    //     sa(&stack_a);
    //     print_St(&stack_a);
    // pa(&stack_b, &stack_a);
    // print_St(&stack_a);
    // printf("\n");
    // print_St(&stack_b);
    // rra(&stack_a);
    // rra(&stack_a);
    // rra(&stack_a);
    // rra(&stack_a);

    // // ra(&stack_a);
    // print_St(&stack_a);
    sort_list(&stack_a, &stack_b);
    // i = is_sorted(&stack_a);
    // printf("%d", i);
    // printf("%d", min);
    // min = get_min_pos(&stack_a);
    // print_St(&stack_a);
    // pb(&stack_a, &stack_b);
    // print_St(&stack_a);

    // print_St(&stack_b);
    // printf("\n");
    print_St(&stack_a);

    // print_St(&stack_a);
}
