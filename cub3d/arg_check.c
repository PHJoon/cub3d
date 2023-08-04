#include "main.h"

static t_flag  check_arg_cnt(int ac)
{
    if (ac != 2)
        return (FAIL);
    return (SUCCESS);
}

static t_flag check_arg_ext(char *arg)
{
    static  char *idf = ".cub";
    int       cnt;
    size_t  idx;

    cnt = 5;
    idx = ft_strlen(arg);
    while (cnt)
    {
        if (arg[idx--] != idf[cnt - 1])
            return (FAIL);
        cnt--;
    }
    return (SUCCESS);
}

t_flag  check_arg(int ac, char **av)
{
    if (check_arg_cnt(ac) == FAIL)
        return (print_error("Wrong number of argument"));
    if (check_arg_ext(av[1]) == FAIL)
        return (print_error("Extension of the filename is not correct"));
    return (SUCCESS);
}