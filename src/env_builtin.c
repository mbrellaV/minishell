#include "../inc/minishell.h"

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

int     full_env(char **mas, char ***envl)
{
	int		len;
	char	**dopenvl;
	char	*dopstr;

	//ft_printf("%d %s ", ft_strcmp(mas[0], "env"), mas[0]);
	dopenvl = *envl;
	if (ft_strcmp(mas[0], "env") == 0)
	{
		show_env(*envl);
		return (0);
	}
	else
	{
		len = 0;
		while (dopenvl[len] != NULL)
		{
			dopstr = ft_strjoin(mas[1], "=");
			if (ft_strstr(dopenvl[len], dopstr) == dopenvl[len])
				dopenvl[len][0] = -128;
			len++;
			ft_strdel(&dopstr);
		}
		*envl = dopenvl;
        if (ft_strcmp(mas[0], "setenv") == 0)
            return (ft_setenv(mas, envl, *envl, 1));
        else if (ft_strcmp(mas[0], "unsetenv") == 0)
		    return (ft_setenv(mas, envl, *envl, 0));
	}
	return (0);
}

int     ft_setenv(char **mas, char ***envl, char **dopmas, int type)
{
	int		len;
	int		i;
	char	**dopenvl;
	int		c;

	len = 0;
	i = 0;
	c = 0;
	while (dopmas[i])
	{
		if (dopmas[i][0] == -128)
			len--;
		len++;
		i++;
	}
	i = 0;
	if (!(dopenvl = (char **)malloc(sizeof(char **) * (len + 1 + type))))
		return (-1);
	while (dopmas[c] != NULL)
	{
		if (dopmas[c][0] != -128)
		{

			dopenvl[i] = (char *)malloc(sizeof(char *) * ft_strlen(dopmas[c]));
			ft_strcpy(dopenvl[i], dopmas[c]);
			dopenvl[i][ft_strlen(dopmas[c]) + 1] = '\0';
			i++;
		}
		c++;
	}
	if (type == 1)
    {
        dopenvl[i] = (char *)malloc(sizeof(char *) * (ft_strlen(mas[1]) + ft_strlen(mas[2]) + 2));
        ft_strcat(dopenvl[i], mas[1]);
        ft_strcat(dopenvl[i], "=");
        ft_strcat(dopenvl[i], mas[2]);
        i++;
    }
	dopenvl[i] = NULL;
	//free_dmas(dopmas);
	*envl = dopenvl;
	return (0);
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