#include "../inc/minishell.h"

int		isdelim(char *a, char b)
{
	while (*a)
	{
		if (*a == b)
			return (1);
		if (b == '"' || b == 96)
			return (2);
		a++;
	}
	return (0);
}

int		c_size(char *str, char b)
{
	int i;

	i = 0;
	while (*str && *str != b)
	{
		i++;
		str++;
	}
	if (*str == '\0')
		return (-1);
	return (i);
}

int		word_size(char *str)
{
	int i;

	i = 0;
	if (isdelim("\t ", *str) == 2)
		c_size(str, *str);
	if (isdelim("\t ", str[0]) || *str == '\0')
		return (0);
	while (*str)
	{
		if (isdelim("\t ", *str))
			return (i);
		i++;
		str++;
	}
	return (i);
}

int		count_words(char *str)
{
	int i;

	i = 0;
	while(*str)
	{
		if (word_size(str) == 1)
		{
			str += word_size(str);
			i++;
		}
		else
			str++;
	}
	return (i);
}

char	**ft_split_echo(char *str)
{
	char	**mas;
	int		cn;
	int		i;
	int		cn_words;

	cn_words = count_words(str) + 1;
	ft_printf(" %d ", cn_words);
	if (cn_words == 0)
		return (NULL);
	i = 0;
	cn = 0;
	mas = (char **)malloc(sizeof(char **) * cn_words);
	while (i < (cn_words - 1) && str[cn])
	{

		if (word_size(str + cn) != 0 && str[cn])
		{
			ft_printf(" 1: len: %d cn: %d ", word_size(str + cn) + cn, cn);
			mas[i] = ft_strsub(str, cn, word_size(str + cn) + cn);
			ft_printf(" str: %s ", mas[i]);
			cn += word_size(str + cn);
			i++;
		}
		else
			cn++;
		ft_printf(" 2: len: %d cn: %d ", word_size(str + cn), cn);
	}
	mas[i] = NULL;
	return (mas);
}