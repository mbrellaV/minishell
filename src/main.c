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
	char	**mas;
	int		tmp;

	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_split_echo(line, " \t=")))
		return (ft_error(15));
	if (ft_strcmp(mas[0], "exit") == 0)
		return (ft_error_with(1, &mas));
	else if (ft_strstr(mas[0], "env") && !ft_strstr(mas[0], "/"))
		full_env(mas, env);
	else if (ft_strcmp(mas[0], "cd") == 0)
		do_cd(mas, env);
	else if (ft_strcmp(mas[0], "pwd") == 0)
		print_path();
	else if (ft_strcmp(mas[0], "echo") == 0)
		do_echo(line, *env);
	else if ((tmp = full_exe(mas, *env)) == -1)
		return (ft_error_with(8, &mas));
	else if (tmp != 1)
		ft_printf("minishell: command not found: %s\n", mas[0]);
	free_dmas(&mas);
	return (0);
}

void	kill_pid(void)
{
	if (g_pid == -100)
	{
		ft_printf("\r$>    ");
		ft_printf("\n$> ");
	}
	else
	{
		kill(g_pid, SIGINT);
		ft_putchar('\n');
	}
	g_pid = -100;
}

int		minishell(char ***envl)
{
	char	*cmd;
	char	**dopenvl;

	g_pid = -100;
	dopenvl = *envl;
	signal(SIGINT, kill_pid);
	ft_printf("$> ");
	while (1)
	{
		if (get_next_line(0, &cmd) != -1)
		{
			if (parse_cmd(cmd, envl) == -2)
			{
				ft_strdel(&cmd);
				free_dmas(&dopenvl);
				exit(0);
			}
			ft_printf("$> ");
			ft_strdel(&cmd);
		}
	}
}

char		**make_env(char **envl)
{
	char	**dopmas;
	int		i;
	char	**dopenvl;

	i = 0;
	dopmas = envl;
	if (!(dopenvl = (char **)malloc(sizeof(char **) * (ft_maslen(dopmas) + 1))))
		return (NULL);
	while (dopmas[i] != NULL)
	{
		if (!(dopenvl[i] = (char *)malloc(sizeof(char *)
				* (ft_strlen(dopmas[i] + 1)))))
			return (NULL);
		ft_strcpy(dopenvl[i], dopmas[i]);
		dopenvl[i][ft_strlen(dopmas[i]) + 1] = '\0';
		i++;
	}
	dopmas[i] = NULL;
	return (dopmas);
}

int		main(int argc, char **argv, char **envl)
{
	if (!(envl = make_env(envl)))
	{
		ft_error(15);
		exit(0);
	}
	minishell(&envl);
	return (0);
}
