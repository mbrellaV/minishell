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

	if (!line || *line == '\0')
		return (0);
	if (ft_strcmp(line, "exit") == 0)
		return (-1);
	if (ft_strcmp(line, "cd") == 0)
		return (-1);
	if (ft_strcmp(line, "pwd") == 0)
	{
		getcwd(path, sizeof(path));
		ft_printf(" %s ", path);
	}
	return (0);
}

int		main()
{
	char	path[1024];
	char	*cmd;

	getcwd(path, sizeof(path));
	ft_printf(" %s ", path);
	while (1)
	{
		if (get_next_line(0, &cmd) != -1)
		{
			if (parse_cmd(cmd) == -1)
				exit(0);
		}

	}
}