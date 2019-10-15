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

int		parse_cmd(char *line)
{
	char	path[1024];
	char	**mas;

	if (!line || *line == '\0')
		return (0);
	if (!(mas = ft_strsplit(line, ' ')))
		return (-1);
	if (ft_strcmp(mas[0], "exit") == 0)
		return (-1);
	if (ft_strcmp(mas[0], "cd") == 0)
		do_cd(mas);
	if (ft_strcmp(mas[0], "pwd") == 0)
	{
		getcwd(path, sizeof(path));
		ft_printf("%s\n", path);
	}
	else
		do_exe(mas);
	return (0);
}

int		minishell(char **envl)
{
	char	path[1024];
	char	*cmd;

	getcwd(path, sizeof(path));
	ft_printf("$> ");
	while (1)
	{
		if (get_next_line(0, &cmd) != -1)
		{
			if (parse_cmd(cmd) == -1)
				exit(0);
			ft_printf("$> ");
		}
	}
	return (0);
}

int		main(int argc, char **argv, char **envl)
{
	minishell(envl);
	return (0);
}