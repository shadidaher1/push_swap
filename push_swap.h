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

typedef struct s_stats
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total_ops;
    int bench_mode; 
    float   disorder;
} t_stats;


void is_number( int argc, char **argv, int start);
void throw_error();
long ftt_atoi(const char *nptr);
void check_double(int argc, char **arg, int start);
void create_stack(t_stack *stack_a, int start, int argc, char **argv);

void ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void sb(t_stack *stack, t_stats *stats);
void sa(t_stack *stack, t_stats *stats);
void swap(t_stack *stack);
void init_stack(t_stack *stack);
void pa(t_stack *a, t_stack *b, t_stats *stats);
void pb(t_stack *a, t_stack *b, t_stats *stats);
void ra(t_stack *stack_a, t_stats *stats);
void rb(t_stack *stack_b, t_stats *stats);
void rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void rra(t_stack *stack, t_stats *stats);
void rrb(t_stack *stack, t_stats *stats);
void rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
int get_min_pos(t_stack *stack);
void simple_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
int is_sorted(t_stack *stack_a);
void assgin_indices(t_stack *stack_a);
void medium_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats );
int find_highest_index(t_stack *stack);
void radix_sort(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	adaptive_sort(t_stack *a, t_stack *b, t_stats *stats);
void print_bench(t_stats *stats, char *strategy);
char *get_strategy_name(char *strategy, float disorder);
int parse_flags(int argc, char **argv, char **strategy, t_stats *stats);

 float	calculate_disorder(t_stack *a);





#endif