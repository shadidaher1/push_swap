#include "push_swap.h"
#include "Libft/libft.h"

int parse_flags(int argc, char **argv, char **strategy, t_stats *stats)
{
    int i;

    i = 1;
    *strategy = "adaptive"; 
    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
        if (ft_strncmp(argv[i], "--bench", 8) == 0)
            stats->bench_mode = 1;
        else if (ft_strncmp(argv[i], "--simple", 9) == 0)
            *strategy = "simple";
        else if (ft_strncmp(argv[i], "--medium", 9) == 0)
            *strategy = "medium";
        else if (ft_strncmp(argv[i], "--complex", 10) == 0)
            *strategy = "complex";
        else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
            *strategy = "adaptive";
        else
            throw_error(); 
        i++;
    }
    return (i); 
}
 float	calculate_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_node	*current_i;
	t_node	*current_j;

	mistakes = 0;
	total_pairs = 0;
	current_i = a->head;
	while (current_i)
	{
		current_j = current_i->next;
		while (current_j)
		{
			total_pairs++;
			if (current_i->index > current_j->index)
				mistakes++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	adaptive_sort(t_stack *a, t_stack *b, t_stats *stats)
{ 
	float	disorder;

    if (is_sorted(a))
        return ;
    if (a->size <= 3)
    {
        simple_sort(a, b, stats);
        return ;
    }
      disorder = stats->disorder;
	if (disorder < 0.2)
		simple_sort(a, b, stats);
	else if (disorder < 0.8)
		medium_sort(a, b, stats);
	else
		radix_sort(a, b, stats);
}