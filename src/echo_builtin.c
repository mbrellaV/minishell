
#include "../inc/minishell.h"

int		do_echo(char *line)
{
	char	**mas;

	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_strsplit(line, ' ')))
		return (-1);
}