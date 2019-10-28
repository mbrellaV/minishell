#include "../inc/minishell.h"

int		go_to_dir(char *line, char ***envl)
{
	char	*dopline;
	char	path[1024];
	char	**splitline;

	getcwd(path, sizeof(path));
	if (!(dopline = ft_strjoin("setenv OLDPWD ", path)))
		return (-1);
	if (!(splitline = ft_split_echo(dopline, " ")))
		return (-1);
	full_env(splitline, envl);
	ft_strdel(&dopline);
	free_dmas(splitline);
	if (access(line, 0) == 0)
	{
		if (!(dopline = ft_strjoin("setenv PWD ", line)))
			return (-1);
		if (!(splitline = ft_split_echo(dopline, " ")))
			return (-1);
		chdir(line);
		full_env(splitline, envl);
		ft_strdel(&dopline);
		free_dmas(splitline);
		return (0);
	}
	ft_printf("cant open folder");
	return (-1);
}

char	*ft_parse_cd(char **mas, char ***envl, char *homepath)
{
	char	*dopline;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!(dopline = (char *)malloc(sizeof(char) * 1024)))
		return (NULL);
	while (mas[1][i])
	{
		if (mas[1][i] == '~')
		{
			ft_strcpy(&dopline[c], homepath);
			c += (int)ft_strlen(homepath) - 1;
		}
		else
			dopline[c] = mas[1][i];
		i++;
		c++;
	}
	return (dopline);
}

int     do_cd(char **mas, char ***envl)
{
	char	*line;
	char	*homepath;


	if (!(homepath = find_var("HOME", *envl)))
		return (-1);
    if (mas[1] == NULL)
	{
    	go_to_dir(homepath, envl);
		return (0);
	}
    else if (ft_strcmp(mas[0], "cd") == 0 && ft_strcmp(mas[1], "-") == 0 && !mas[2])
	{
    	line = find_var("OLDPWD", *envl);
		go_to_dir(line, envl);
		ft_strdel(&line);
		return (0);
	}
    else if (mas[2] != NULL)
        return(-1);
    line = ft_parse_cd(mas, envl, homepath);
    go_to_dir(line, envl);
    ft_strdel(&line);
    return (0);
}