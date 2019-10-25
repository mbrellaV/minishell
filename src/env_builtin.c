#include "../inc/minishell.h"

int		del_mas()
{

}

int		sort_env(char **mas)
{
	int 	d;
	int 	i;
	int		len;
	char	*dop;

	d = 0;
	len = 0;
	while (mas[len])
		len++;
	while (d < len)
	{
		i = 0;
		while (mas[i + 1])
		{
			if (ft_strcmp(mas[i], mas[i + 1]) > 0)
			{
				dop = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = dop;
			}
			i++;
		}
		d++;
	}
	return (0);
}

char	**full_env(char **mas, char ***envl)
{
	int		len;
	char	**dopenvl;
	char	**dopmas;
	char	**tmp;

	if (ft_strcmp(mas[0], "env"))
	{
		show_env(mas);
		return (NULL);
	}
	if (ft_strcmp(mas[0], "setenv"))
		return (ft_setenv(mas, envl));
	else
	{
		len = 0;
		while (*envl[len])
		{
			dopmas = ft_split_echo(*envl[len], "=");
			tmp = dopmas;
			if (ft_strcmp(dopmas[0], mas[1]) == 0)
				*envl[len][0] = -128;
			len++;
			ft_strdel(tmp);
		}
		return (ft_setenv(mas, envl));
	}
}

char	**ft_setenv(char **mas, char ***envl)
{
	int		len;
	int		i;
	char	**dopenvl;
	int		c;

	len = 0;
	i = 0;
	c = 0;
	while (envl[len])
	{
		if (*envl[len][0] == -128)
			len--;
		len++;
	}
	dopenvl = (char **)malloc(sizeof(char **) * (len + 2));
	while (i < len)
	{
		if (*envl[i][0] != -128)
		{
			dopenvl[i] = (char *)malloc(sizeof(char *) * ft_strlen(*envl[i]));
			ft_strcpy(dopenvl[i], *envl[c]);
			i++;
		}
		c++;
	}
	dopenvl[i] = (char *)malloc(sizeof(char *) * (ft_strlen(mas[1]) + ft_strlen(mas[2]) + 2));
	ft_strcat(dopenvl[i], mas[1]);
	ft_strcat(dopenvl[i], "=");
	ft_strcat(dopenvl[i], mas[2]);
	*envl = dopenvl;
	return (dopenvl);
}

int     show_env(char **mas)
{
    int n;

    n = 0;
    if (sort_env(mas) == -1)
    	return (0);
    while (mas[n])
    {
        ft_printf("%s\n", mas[n]);
        n++;
    }
    return (0);
}