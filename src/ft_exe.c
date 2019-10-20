
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

int		do_exe(char **mas)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(mas[0], mas, NULL) == -1)
			return (-1);
	}
	else if (pid == -1)
	{
		ft_printf("error");
		return (-1);
	}
	else
		wait(&pid);
	return (0);
}

int		find_exe(char *dir_name, char *filename)
{
	struct dirent	*pdirent;
	DIR				*dire;


	if (!(dire = opendir(dir_name)))
	{
		ft_printf("ls: %sl: ", dir_name);
		return (-1);
	}
	while ((pdirent = readdir(dire)) != NULL)
	{
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
	char	**dopmas;

	i = 0;
	if (ft_strstr(mas[0], "/"))
	{
		if (!(dir_name = ft_strsub(mas[0], 0, find_last(mas[0], '/'))))
			return (-1);
		if (!(filename = ft_strsub(mas[0], find_last(mas[0], '/') + 1, ft_strlen(mas[0]))))
			return (-1);
		if (find_exe(dir_name, filename))
			do_exe(mas);
	}
	else
	{
		while (envl[i])
		{
			if ((dopmas = ft_split_echo(envl[i], "=:")))
			{
				if (ft_strcmp(dopmas[0], "PATH") == 0)
				{
					i = 1;
					while (dopmas[i])
					{
						if (find_exe(dopmas[i], mas[0]))
						{
							mas[0] = ft_strjoin(dopmas[i], mas[0]);
							do_exe(mas);
							return (1);
						}
						i++;
					}
				}

			}
		}
	}
	return (0);
}