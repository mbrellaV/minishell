
#include "../inc/minishell.h"

int		ft_strfind_indexd(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*find_var(char *dop, char **envl)
{
	int		i;
	char	*dopd;

	i = 0;
	dopd = ft_strjoin(dop, "=");
	while (envl[i])
	{
		if (ft_strstr(envl[i], dopd) == envl[i])
		{
			dop = ft_strsub(envl[i], ft_strlen(dopd), ft_strlen(envl[i]) - ft_strlen(dopd));
			ft_strdel(&dopd);
			return (dop);
		}
		i++;
	}
	return (NULL);
}

int		do_echo(char *line, char **envl)
{
	char	**mas;
	int		i;
	int     c;
	char    *dop;
	char	*tmp;

	i = 1;
	c = 0;
	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_split_echo(line, " \t")))
		return (-1);
	while (mas[i])
	{
		c = 0;
	    while (mas[i][c])
        {
	        if (mas[i][c] == '$')
			{
				dop = ft_strsub(mas[i], c + 1, ft_strfind_indexd(&mas[i][c + 1], '$') == -1
				? ft_strlen(mas[i]) - c : ft_strfind_indexd(&mas[i][c + 1], '$'));
				tmp = find_var(dop, envl);
				c += ft_strfind_indexd(&mas[i][c + 1], '$') == -1
					 ? (int)ft_strlen(mas[i]) - c : ft_strfind_indexd(&mas[i][c + 1], '$');
				ft_strdel(&dop);
				ft_putstr(tmp);
				ft_strdel(&tmp);
			}
	        else
				ft_putchar(mas[i][c]);
	        c++;
        }
	    ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}