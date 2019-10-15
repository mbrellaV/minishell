#include "../inc/minishell.h"

int     do_cd(char **mas)
{
    if (access(mas[1], 0) == 0)
    {
        chdir(mas[1]);
    }
    else
        ft_printf("error cd");
    return (0);
}