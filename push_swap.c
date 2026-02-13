#include "push_swap.h"
#include <stdio.h>
#include "Libft/libft.h"


void print_St(t_stack *stack)
{
    t_node *current;

    current = stack->head; 
    while (current)
    {
        printf("%d\n", current->number);
        current = current->next; 
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

  
    if (!stack)
        return;

    curr = stack->head;
    
    while (curr)
    {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
   
    stack->head = NULL;
    stack->size = 0;
 
}
static void	clear_all(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
}

char    *get_strat_name(char *flag, float disorder)
{
    
    if (flag && ft_strncmp(flag, "--simple", 9) == 0)
        return ("Simple Sort");
    if (flag && ft_strncmp(flag, "--medium", 9) == 0)
        return ("Medium Sort");
    if (flag && ft_strncmp(flag, "--complex", 10) == 0)
        return ("Radix Sort");
    
    if (disorder < 0.2)
        return ("Adaptive (Simple)");
    if (disorder < 0.5)
        return ("Adaptive (Medium)");
    return ("Adaptive (Complex)");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
	char	*strat_name;
	int		start;

	if (argc < 2)
		return (0);
	ft_memset(&stats, 0, sizeof(t_stats));
	start = parse_flags(argc, argv, &strat_name, &stats);
	if (start >= argc)
		return (0);
	is_number(argc, argv, start);
	create_stack(&a, argc, argv, start);
	init_stack(&b);
	stats.disorder = calculate_disorder(&a);
	if (is_sorted(&a))
	{
		clear_all(&a, &b);
		return (0);
	}
	if (ft_strncmp(strat_name, "simple", 7) == 0)
		simple_sort(&a, &b, &stats);
	else if (ft_strncmp(strat_name, "medium", 7) == 0)
		medium_sort(&a, &b, &stats);
	else if (ft_strncmp(strat_name, "complex", 8) == 0)
		radix_sort(&a, &b, &stats);
	else
		adaptive_sort(&a, &b, &stats);
	if (stats.bench_mode)
	    print_bench(&stats, get_strat_name(argv[1], stats.disorder));
	clear_all(&a, &b);
	return (0);
}
    // int min;
    // int i;
    //     print_St(&stack_a);
    //     sa(&stack_a);
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

// }
