#include "cub3d.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_concat(char *s1, char *s2)
{
	int i;
	int	j;
	int len;
	char *ret;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}