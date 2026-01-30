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



#endif