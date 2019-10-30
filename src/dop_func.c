/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:43:52 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/30 07:43:54 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		ft_maslen(char **mas)
{
	int i;

	i = 0;
	if (!mas)
		return (-1);
	while (mas[i])
		i++;
	return (i);
}

int		ft_maslen_with(char **mas)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!mas)
		return (-1);
	while (mas[i])
	{
		if (mas[i][0] != -128)
			len++;
		i++;
	}
	return (len);
}

int		print_path(void)
{
	char path[1024];

	getcwd(path, sizeof(path));
	ft_printf("%s\n", path);
}

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
