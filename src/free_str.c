#include "../inc/minishell.h"

int		free_dmas(char **mas)
{
	int i;

	i = 0;
	if (!mas)
		return (0);
	while (mas[i])
	{
		ft_strdel(&mas[i]);
		i++;
	}
	free(mas);
	return (0);
}