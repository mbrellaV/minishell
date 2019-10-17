#include "../inc/minishell.h"

static	void	*alldel(char **mas)
{
	while (*mas)
	{
		free(*mas);
		mas++;
	}
	free(mas);
	return (NULL);
}

int		ft_isdelim(char c, char delim)
{
	if (c == delim)
		return (1);
	return (0);
}

int		ft_count_words(char const *s, char c)
{
	unsigned int cn;

	cn = 0;
	if (!s && !c)
		return (cn);
	while (*s)
	{
		while (ft_isdelim(*s, c) && *s)
			s++;
		if (*s != '\0')
			cn++;
		while (!(ft_isdelim(*s, c)) && *s)
			s++;
	}
	return (cn);
}

char	*ft_strsep(char *s, const char delim)
{
	char			*dops;
	unsigned int	i;
	char			dopdelim;

	dopdelim = (char)delim;
	if (!s || !delim)
		return (NULL);
	if (!(dops = (char *)malloc(ft_word_size(s, dopdelim) + 1)))
		return (NULL);
	i = 0;
	while (!ft_isdelim(*s, dopdelim) && *s)
	{
		dops[i] = *s;
		s++;
		i++;
	}
	dops[i] = '\0';
	return (dops);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**mas;
	unsigned int		i;
	unsigned int		cn;

	i = 0;
	cn = 0;
	if (!s || !c)
		return (NULL);
	if (!(mas = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (s[cn])
	{
		while (ft_isdelim(s[cn], c) && s[cn])
			cn++;
		if (s[cn] != '\0')
			if (!(mas[i] = ft_strsep((char*)(s + cn), (const char)c)))
				return (alldel(mas));
		if (s[cn] == '\0')
			i--;
		while (!ft_isdelim(s[cn], c) && s[cn])
			cn++;
		i++;
	}
	mas[i] = NULL;
	return (mas);
}
