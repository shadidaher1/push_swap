#include "push_swap.h"
#include <limits.h>
#include "Libft/libft.h"

// static void validate_double(int argc, char **argv, int i, char **split_a)
// {
//     int a;
//     int b;
//     int k;
//     long num_a;
//     long num_b;
//     char **split_b;
//     int j;

//     j = 0;

//     while (split_a[j])
//     {
//         num_a = ftt_atoi(split_a[j]);
//         a = j + 1;
//         while (split_a[a])
//         {
//             if (num_a == ftt_atoi(split_a[a]))
//                 throw_error();
//             a++;
//         }
//         b = i + 1;
//         while (b < argc)
//         {
//             split_b = ft_split(argv[b], ' ');
//             k = 0;
//             while (split_b[k])
//             {
//                 num_b = ftt_atoi(split_b[k]);
//                 if ((num_a) == num_b)
//                     throw_error();
//                 k++;
//             }
//             b++;
//         }

//         j++;
//     }
// }

// void check_double(int argc, char **argv)
// {
//     int i;
//     char **spllit;
//     int num;
//     int j;
//     int should_free;

//     should_free = 0;
//     if (argc == 2)
//     {
//         spllit = ft_split(argv[1], ' ');
//         i = 0;
//     }
//     else
//     {
//         spllit = argv;
//         i = 1;
//     }

//     while (spllit[i])
//     {
//         num = ftt_atoi(spllit[i]);
//         j = i + 1;
//         while (spllit[j])
//         {
//             if (ftt_atoi(spllit[j]) == num)
//                 if (should_free)
//                     free_split(spllit);
//             throw_error();
//             j++;
//         }
//         i++;
//     }
// }
static void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}

static void check_duplicates(char **split, int start, int should_free)
{
    int i;
    int j;
    int num;

    i = start;
    while (split[i])
    {
        num = ftt_atoi(split[i]);
        j = i + 1;
        while (split[j])
        {
            if (ftt_atoi(split[j]) == num)
            {
                if (should_free)
                    free_split(split);
                throw_error();
            }
            j++;
        }
        i++;
    }
}

void check_double(int argc, char **argv)
{
    char **split;

    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        check_duplicates(split, 0, 1);
        free_split(split);
    }
    else
        check_duplicates(argv, 1, 0);
}

long ftt_atoi(const char *nptr)
{
    int i;
    int sign;
    long result;

    result = 0;
    sign = 1;
    i = 0;
    while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    result = result * sign;
    if (result > INT_MAX || result < INT_MIN)
        throw_error();
    return (result);
}