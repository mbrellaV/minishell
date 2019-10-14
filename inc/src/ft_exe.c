
#include "../inc/minishell.h"

int		do_exe(char **mas)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(mas[0], mas, NULL);
	}
	else if (pid == -1)
		ft_printf("error");
	else
		wait(&pid);
	return (0);
}