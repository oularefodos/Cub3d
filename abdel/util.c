#include <stdlib.h>
#include "cub3d.h"



size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize < 1)
		return (i);
	while ((j < dstsize - 1) && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

static size_t	taille_tab(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && s++)
	{
		while (*s != c && *s)
			s++;
		cnt++;
		while (*s == c && *s)
			s++;
	}
	return (cnt);
}

static int	remp_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s != c && *s && ++s)
			len++;
		tab[i] = malloc(len + 1);
		if (!tab[i])
		{
			while (i)
				free(tab[--i]);
			free(tab);
			return (1);
		}
		ft_strlcpy(tab[i++], s - len, len + 1);
		while (*s == c && *s)
			s++;
	}
	tab[i] = 0;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	tab = (char **)malloc(sizeof(char *) * (taille_tab(s, c) + 1));
	if (!tab)
		return (NULL);
	if (remp_tab(s, c, tab))
		return (NULL);
	return (tab);
}


