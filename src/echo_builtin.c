
#include "../inc/minishell.h"

int		do_echo(char *line)
{
	char	**mas;
	int		i;

	i = 1;
	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_split_echo(line)))
		return (-1);
	while (mas[i])
	{
		//ft_printf("i: %d ", i);
		ft_printf("|%s|", mas[i]);
		//ft_putstr(mas[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}