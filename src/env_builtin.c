#include "../inc/minishell.h"

int     show_env(char **mas)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (mas[n])
    {
        ft_printf("%s\n", mas[n]);
        n++;
    }
    return (0);
}