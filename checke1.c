#include "push_swap.h"
#include "Libft/libft.h"

static int is_valid_char(char c)
{
    return (ft_isdigit(c) || c == ' ' || c == '+' || c == '-');
}
static void check_sign(int i, char *str)
{
    if (str[i] == '+' || str[i] == '-')
    {

        if (i > 0 && str[i - 1] != ' ')
            throw_error();
        if (!ft_isdigit(str[i + 1]))
            throw_error();
    }
}

static void validate_string(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        throw_error();
    while (str[i])
    {
        if (!(is_valid_char(str[i])))
            throw_error();
        check_sign(i, str);
        // if (str[i] == ' ' && !ft_isdigit(str[i - 1]))
        //     throw_error();
        i++;
    }
}


void is_number(int argc, char **argv)
{
    int i;

    if (argc == 1)
        return;
    i = 1;
    while (i < argc)
    {
        validate_string(argv[i]);
        i++;
    }
    check_double(argc, argv);
}

void throw_error()
{
    write(2, "Error\n", 6);
    exit(1);
}