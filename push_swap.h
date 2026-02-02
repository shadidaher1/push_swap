#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int number;
    int index;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *head;
    t_node *tail;
    int size;
    float disorder;
} t_stack;

void is_number(int argc, char **argv);
void throw_error();
long ftt_atoi(const char *nptr);
void check_double(int argc, char **argv);
void create_stack(t_stack *stack_a, int argc, char **argv);
void ss(t_stack *stack_a, t_stack *stack_b);
void sb(t_stack *stack);
void sa(t_stack *stack);
void swap(t_stack *stack);
void init_stack(t_stack *stack);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack_a, t_stack *stack_b);
int get_min_pos(t_stack *stack);
void sort_list(t_stack *stack_a, t_stack *stack_b);
int is_sorted(t_stack *stack_a);
void assgin_indices(t_stack *stack_a);
void sort_chunk(t_stack *stack_a, t_stack *stack_b );
 int find_highest_index(t_stack *stack);



#endif