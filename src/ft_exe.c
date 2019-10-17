
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

int		find_exe(char **mas)
{
	struct dirent	*pdirent;
	DIR				*dire;
	char			*dir_name;
	char			*file_name;

	if (!(dir_name = ft_strsub(mas[0], 0, find_last(mas[0], '/'))))
		return (-1);
	if (!(file_name = ft_strsub(mas[0], find_last(mas[0], '/') + 1, ft_strlen(mas[0]))))
		return (-1);
	if (!(dire = opendir(dir_name)))
	{
		ft_printf("ls: %sl: ", dir_name);
		return (-1);
	}
	while ((pdirent = readdir(dire)) != NULL)
	{
		if (ft_strcmp(pdirent->d_name, file_name) == 0)
			return (do_exe(mas));
	}
	ft_strdel(&dir_name);
	closedir(dire);
	return (1);
}