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
void print_index(t_stack *stack_a)
{
    t_node *tmp;

    tmp = stack_a->head;
    while (tmp)
    {
        printf("%d\n",tmp->index);
        tmp = tmp->next;
    }
}

void print_head(t_stack *stack)
{
    printf("%d", stack->head->number);
}
void clear_stack(t_stack *stack)
{
    t_node *curr;
    t_node *next_node;

    // 1. If stack is NULL, just return
    if (!stack)
        return;

    curr = stack->head;
    // 2. Loop through and free every node
    while (curr)
    {
        next_node = curr->next;
        free(curr); // This is correct: nodes were malloc'd
        curr = next_node;
    }
    // 3. Reset the head and size so the stack is "empty"
    stack->head = NULL;
    stack->size = 0;
    
    // IMPORTANT: Remove free(stack); 
    // Because stack_a and stack_b are local variables in main.
}
int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    
    is_number(argc, argv);
    create_stack(&stack_a, argc, argv);
    init_stack(&stack_b);
    sort_chunk(&stack_a,&stack_b);
    print_St(&stack_a);
    clear_stack(&stack_a);
    clear_stack(&stack_b);
    // int min;
    // int i;
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
    // sort_list(&stack_a, &stack_b);
    // i = is_sorted(&stack_a);
    // printf("%d", i);
    // printf("%d", min);
    // min = get_min_pos(&stack_a);
    // print_St(&stack_a);
    // pb(&stack_a, &stack_b);
    // print_St(&stack_a);

    // print_St(&stack_b);
    // printf("\n");
    // assgin_indices(&stack_a);
    // print_St(&stack_a);
    // print_index(&stack_a);
    // int k = find_highest_index(&stack_a);
    // printf("%d",k);
    // print_St(&stack_b);

}
