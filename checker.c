// #include "push_swap.h"
// #include "Libft/libft.h"
// #include "ft_printf/ft_printf.h"

// void is_number(int argc, char **argv)
// {
//     int i, j;

//     if (argc == 1)
//         return;
//     i = 1;
//     while (i < argc)
//     {
//         j = 0;
//         if (!argv[i][j])
//             throw_error();
//         if (argv[i][j] == '+' || argv[i][j] == '-')
//             j++;
//         while (argv[i][j])
//         {
//             if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j - 1] != ' '))
//                 throw_error();
//             if (argv[i][j] == '+' || argv[i][j] == '-')
//                 j++;
//             if (argv[i][j] == ' ' && !(ft_isdigit(argv[i][j - 1])))
//                 throw_error();
//             if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '))
//                 throw_error();
//             j++;
//         }
//         i++;
//     }
// }
// void throw_error()
// {
//     write(2, "Error\n", 6);
//     exit(1);
// }
