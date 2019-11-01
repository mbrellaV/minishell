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

	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_split_echo(line, " \t=")))
		return (0);
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
	else if (do_rest(mas[0], mas, env) != 0)
		return (-1);
	free_dmas(&mas);
	return (0);
}

void	kill_pid(int a)
{
	a = 0;
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

	g_pid = -100;
	signal(SIGINT, kill_pid);
	ft_printf("$> ");
	while (1)
	{
		if (get_next_line(0, &cmd) != -1)
		{
			if (parse_cmd(cmd, envl) == -2)
			{
				ft_strdel(&cmd);
				free_dmas(envl);
				exit(0);
			}
			ft_printf("$> ");
			ft_strdel(&cmd);
		}
	}
}

char		**make_env(char ***envl, char ***normenv)
{
	char	**dopmas;
	int		i;
	char	**dopenvl;

	i = 0;
	dopmas = *envl;
	if (!(dopenvl = (char **)ft_memalloc(sizeof(char **) * (ft_maslen(dopmas) + 1))))
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
	dopenvl[i] = NULL;
	*normenv = dopenvl;
	return (dopenvl);
}

int		main(int argc, char **argv, char **envl)
{
	char	***env;

	env = &envl;
	if (!make_env(&envl, env))
	{
		ft_error(15);
		exit(0);
	}
	minishell(env);
	return (0);
}
