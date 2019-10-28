
#include "../inc/minishell.h"

int		find_last(char *line, char c)
{
	int		i;
	int		res;

	i = 0;
	res = -1;
	while (line[i])
	{
		if (line[i] == c)
			res = i;
		i++;
	}
	return (res);
}

int		do_exe(char **mas, char **envl)
{
	g_pid = fork();
	if (g_pid == 0)
	{
		if (execve(mas[0], mas, envl) == -1)
			return (-1);
	}
	else if (g_pid == -1)
	{
		ft_printf("error");
		return (-1);
	}
	else
		wait(&g_pid);
	//exit(0);
	return (0);
}

int		find_exe(char *dir_name, char *filename)
{
	struct dirent	*pdirent;
	DIR				*dire;

	if (!(dire = opendir(dir_name)))
	{
		ft_printf("cant open: %sl: ", dir_name);
		return (-1);
	}
	while ((pdirent = readdir(dire)) != NULL)
	{
		//if (ft_strstr(pdirent->d_name, filename) == pdirent->d_name)
		if (ft_strcmp(pdirent->d_name, filename) == 0)
			return (1);

	}
	ft_strdel(&dir_name);
	closedir(dire);
	return (0);
}

int		full_exe(char **mas, char **envl)
{
	char	*dir_name;
	char	*filename;
	int		i;
	int     d;
	char	**dopmas;

	i = 0;
	d = 0;
	if (find_last(mas[0], '/') != -1)
	{
		if (!(dir_name = ft_strsub(mas[0], 0, find_last(mas[0], '/'))))
			return (-1);
		if (!(filename = ft_strsub(mas[0], find_last(mas[0], '/') + 1, ft_strlen(mas[0]))))
			return (-1);
		if (find_exe(dir_name, filename))
        {
            do_exe(mas, envl);
            return (1);
        }
	}
	else
	{
		while (envl[d])
		{
            if (ft_strstr(envl[d], "PATH=") == envl[d])
            {
                if (!(dopmas = ft_split_echo(envl[d], "=: ")))
                    return (-1);
                i = 1;
                while (dopmas[i])
                {
                    if (find_exe(dopmas[i], mas[0]))
                    {
                        mas[0] = ft_strjoin(ft_strjoin(dopmas[i], "/"), mas[0]);
                        do_exe(mas, envl);
                        return (1);
                    }
                    i++;
                }
            }
			d++;
		}
	}
	return (-1);
}