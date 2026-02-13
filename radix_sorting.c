#include "push_swap.h"

void radix_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
    int     i;
    int     j;
    int     size;
    int     max_bits;

    size = stack_a->size;
    max_bits = 0;
 
    assgin_indices(stack_a);
    while (((size - 1) >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
          
            if (((stack_a->head->index >> i) & 1) == 0)
                pb(stack_a, stack_b, stats);
            else
                ra(stack_a, stats);
            j++;
        }
        
        while (stack_b->size > 0)
            pa(stack_a, stack_b, stats);
        i++;
    }

}