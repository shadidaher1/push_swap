#include "push_swap.h"
#include <math.h>
#include<stdio.h>

void assgin_indices(t_stack *stack_a)
{
    t_node *curr;
    t_node *next;

    curr = stack_a->head;
    while (curr)
    {
        curr->index = 0; 
        next = stack_a->head;
        while (next)
        {

            if (curr->number > next->number)
                curr->index++;
            next = next->next;
        }
            curr = curr->next;
    }
}

int find_highest_index(t_stack *stack)
{
    int count;
    t_node *tmp;
    int max_pos;
    int max_ind;

    max_pos = 0;
    count = 0;
    max_ind = -1;
    tmp = stack->head;
    while(tmp)
    {
        if (tmp->index > max_ind)
        {
            max_pos = count;
            max_ind = tmp->index;
        }    

        tmp = tmp->next;
        count++;
    }
    return (max_pos);

}

static void bring_back(t_stack *stack_a, t_stack *stack_b)
{
    int pos;
    int     rot_lef;

    while (stack_b->size >0)
    {
        pos = find_highest_index(stack_b);
        if (pos <= stack_b->size / 2)
        {
            
            while (pos >0)
            {
                rb(stack_b);
                pos--;
                
            }
        }
       else
       {
           rot_lef =stack_b->size- pos ;
           while (rot_lef > 0)
           {
               rrb(stack_b);
                rot_lef--;
            }
            
        }
        pa (stack_a,stack_b);
    }
}

static int i_sqrt(int number)
{
    int i = 1;
    while (i * i <= number)
        i++;
    return (i);
}


void sort_chunk(t_stack *stack_a, t_stack *stack_b )
{
    int chunk_size;
    int i;
   

    i = 0;
    if (is_sorted(stack_a))
        return;
   
    chunk_size = (i_sqrt(stack_a->size) * 1.5  ) ;
    assgin_indices(stack_a);
    while (stack_a->head)
    {
        if (stack_a->head->index <= i)
        {
            pb (stack_a, stack_b);
            i++;
        }
        else if (stack_a->head->index < i + chunk_size)
        {
            pb (stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else
            ra(stack_a);    
        
    }
    bring_back(stack_a, stack_b);
}