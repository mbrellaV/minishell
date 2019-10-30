/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:08:35 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/30 07:08:36 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		isdelim(char *a, char b)
{
	while (*a)
	{
		if (*a == b)
			return (1);
		if (b == 34 || b == 39)
			return (2);
		a++;
	}
	return (0);
}

int		c_size(char *str, char b, char *delim)
{
	int i;
	int dop;

	i = 0;
	str++;
	dop = 0;
	if (*str == b)
		return (0);
	while (*str && *str != b)
	{
		if (isdelim(delim, *str) == 0)
			dop++;
		i++;
		str++;
	}
	if (*str == '\0' && dop > 0)
		return (-1);
	return (i);
}

int		word_size(char *str, char *delim)
{
	int i;

	i = 0;
	if (isdelim(delim, *str) == 2)
		return (c_size(str, *str, delim));
	if (isdelim(delim, str[0]) || *str == '\0')
		return (0);
	while (*str)
	{
		if (isdelim(delim, *str))
			return (i);
		i++;
		str++;
	}
	return (i);
}

int		count_words(char *str, char *delim)
{
	int i;

	i = 0;
	while (*str)
	{
		if (word_size(str, delim) > 0)
		{
			str += word_size(str, delim) + (ISPAR(*str) ? 2 : 0);
			i++;
		}
		else if (word_size(str, delim) == -1)
			return (-1);
		else
			str++;
	}
	return (i);
}

char	**ft_split_echo(char *str, char *delim)
{
	char	**mas;
	int		cn;
	int		i;
	int		cn_words;

	if ((cn_words = count_words(str, delim) + 1) == 0)
		return (NULL);
	i = 0;
	cn = 0;
	if (!(mas = (char **)malloc(sizeof(char **) * cn_words)))
		return (NULL);
	while (i < (cn_words - 1) && str[cn])
		if (word_size(str + cn, delim) > 0 && str[cn])
		{
			if (!(mas[i] = ft_strsub(str, cn + (ISPAR(str[cn]) ? 1 : 0),
					word_size(str + cn, delim))))
				return (NULL);
			cn += word_size(str + cn, delim) + (ISPAR(str[cn]) ? 2 : 0);
			i++;
		}
		else
			cn += 1 + (ISPAR(str[cn]) ? 1 : 0);
	mas[i] = NULL;
	return (mas);
}
