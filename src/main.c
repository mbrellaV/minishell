/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:55:17 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 10:55:20 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		parse_cmd(char *line, char ***env)
{
	char	path[1024];
	char	**mas;

	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_strsplit(line, ' ')))
		return (-1);
	if (ft_strcmp(mas[0], "exit") == 0)
		return (-1);
	else if (ft_strstr(mas[0], "env"))
	    full_env(mas, env);
	else if (ft_strcmp(mas[0], "cd") == 0)
		do_cd(mas);
	else if (ft_strcmp(mas[0], "pwd") == 0)
	{
		getcwd(path, sizeof(path));
		ft_printf("%s\n", path);
	}
	else if (ft_strcmp(mas[0], "echo") == 0)
		do_echo(line, *env);
	else if (full_exe(mas, *env) == -1)
		ft_printf("zsh: command not found: %s\n", mas[0]);
	return (0);
}

void	kill_pid()
{
	if (g_pid == -100)
	{
		ft_printf("\r$>   ");
		ft_printf("\n$> ");
	}
	else
	{
		kill(g_pid, SIGUSR1);
		ft_putchar('\n');
	}
	//ft_putchar('\n');
	g_pid = -100;
}

int		minishell(char ***envl)
{
	char	path[1024];
	char	*cmd;

	g_pid = -100;
	signal(SIGINT, kill_pid);
	getcwd(path, sizeof(path));
	ft_printf("$> ");
	while (1)
	{
		if (get_next_line(0, &cmd) != -1)
		{
			if (parse_cmd(cmd, envl) == -1)
				exit(0);
			ft_printf("$> ");
		}
	}
}

int		main(int argc, char **argv, char **envl)
{
	minishell(&envl);
	return (0);
}