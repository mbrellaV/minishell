#include "../inc/minishell.h"

int		isdelim(char *a, char b)
{
	while (*a)
	{
		if (*a == b)
			return (1);
		if (b == 34 || b == 96)
			return (2);
		a++;
	}
	return (0);
}

int		c_size(char *str, char b)
{
	int i;

	i = 0;
	str++;
	while (*str && *str != b)
	{
		i++;
		str++;
	}
	if (*str == '\0')
		return (-1);
	return (i);
}

int		word_size(char *str, char *delim)
{
	int i;

	i = 0;
	if (isdelim(delim, *str) == 2)
	{
	//	ft_printf("11111 ");
		//intf(" len1: %d %c ", c_size(str, *str), *str);
		return (c_size(str, *str));
	}
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
	while(*str)
	{
		if (word_size(str, delim) > 0)
		{
			str += word_size(str, delim) + 1;
			i++;
		}
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

	cn_words = count_words(str, delim) + 1;
	if (cn_words == 0)
		return (NULL);
	i = 0;
	cn = 0;
	mas = (char **)malloc(sizeof(char **) * cn_words);
	while (i < (cn_words - 1) && str[cn])
	{
		if (word_size(str + cn, delim) != 0 && str[cn])
		{
			mas[i] = ft_strsub(str, cn + (str[cn] == 34 ? 1 : 0), word_size(str + cn, delim));
			cn += word_size(str + cn, delim);
			i++;
		}
		else
			cn++;
	}
	mas[i] = NULL;
	return (mas);
}