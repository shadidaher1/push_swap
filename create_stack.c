#include "push_swap.h"
#include "Libft/libft.h"
void init_stack(t_stack *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    stack->disorder = 0.0;
}

static t_node *create_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        exit(1);
    node->number = value;
    node->index = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

static void assign_value(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = create_node(value);
    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
    }
    else
    {
        stack->tail->next = new_node;
        new_node->prev = stack->tail;
        stack->tail = new_node;
    }
    stack->size++;
}

static void build_stack(t_stack *stack, char **str, int i)
{
    int value;

    while (str[i])
    {
        value = ftt_atoi(str[i]);
        assign_value(stack, value);
        i++;
    }
}

void create_stack(t_stack *stack_a, int argc, char **argv)
{
    char **split;

    init_stack(stack_a);
    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        build_stack(stack_a, split, 0);
    }
    else
        build_stack(stack_a, argv, 1);
}