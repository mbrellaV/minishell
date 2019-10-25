#include "../inc/minishell.h"

char	*ft_parse_cd(char **mas)
{
	char	*dopline;
	int		i;
	int		c;

	i = 0;
	c = 0;
	dopline = (char *)malloc(sizeof(char) * 1024);
	while (mas[1][i])
	{
		if (mas[1][i] == '~')
		{
			ft_strcpy(&dopline[c], HOMEPATH);
			c += (int)ft_strlen(HOMEPATH) - 1;
		}
		else
			dopline[c] = mas[1][i];
		i++;
		c++;
	}
	ft_printf("%s", dopline);
	return (dopline);
}

int     do_cd(char **mas)
{
	char	*line;
    if (mas[1] == NULL)
	{
		chdir(HOMEPATH);
		return (0);
	}
    else if (mas[2] != NULL)
        return(-1);
    line = ft_parse_cd(mas);
    if (access(line, 0) == 0)
        chdir(line);
    else
        ft_printf("invalid folder");
    return (0);
}