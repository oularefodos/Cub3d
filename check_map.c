#include "cub3d.h"

int ft_pos(char c)
{
	char *str;
	int i;

	i = 0;
	str = "0NWSE";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int find_error(t_map *map)
{
	int x;
	int y;
	int n;

	x = 0;
	y = 0;
	n = 0;
	while (map->buf[y])
	{
		x = 0;
		while (map->buf[y][x])
		{
			if (map->buf[y][0] == '\n')
				return (1);
			if (map->buf[y][x] == 'N' || map->buf[y][x] == 'W' 
				|| map->buf[y][x] == 'E'|| map->buf[y][x] == 'S')
			{
				map->player_x = x;
				map->player_y = y;
				n++;
			}
			if (map->buf[y][x] != 'N' && map->buf[y][x] != 'W' && map->buf[y][x] != '0' && map->buf[y][x] != 32
				&& map->buf[y][x] != 'E' && map->buf[y][x] != 'S' && map->buf[y][x] != '1')
				return (1);
			if (map->buf[y][x] == 32)
			{
				if (ft_pos(map->buf[y][x + 1])|| (x != 0 && ft_pos(map->buf[y][x - 1]))
					|| (map->buf[y + 1] && ft_pos(map->buf[y + 1][x]))
					|| (y != 0 && ft_pos(map->buf[y - 1][x])))
					return (1);
			}
			if ((map->buf[y][x] != '1' && map->buf[y][x] != ' ') && (!map->buf[y][x + 1] || !x || !y || !map->buf[y + 1]))
				return (1);
			x++;
		}
		y++;
	}
	if (n != 1)
		return (1);
	return (0);
}

char *ft_duplic(char *str, int size)
{
	int i;
	char *ret;

	i = 0;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	while (i < size)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

char **getmap(char *str, int len, int nline)
{
	char **buf;
	int i;
	int m;

	i = 0;
	m = 0;
	buf = malloc(sizeof(char *) * (nline + 1));
	if (!buf)
		return (NULL);
	while (i < nline)
	{
		m = 0;
		while (*str && *str != '\n')
		{
			str++;
			m++;
		}
		buf[i] = ft_duplic(str - m, len);
		if (*str == '\n')
			str++;
		i++;
	}
	buf[i] = NULL;
	return (buf);
}

int maxlen(char *str, int *nline)
{
	int i;
	int ret;
	int count;

	i = 0;
	ret = 0;
	*nline = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			count++;
		}
		else if (str[i] == '\n' || str[i + 1] == '\0')
		{
			(*nline)++;
			if (count > ret)
				ret = count;
			count = 0;
		}
		i++;
	}
	return (ret);
}

int check_map(t_map *map, char *str)
{
	int len;
	int nline;

	nline = 0;
	len = maxlen(str, &nline);
	map->heigth = 640 * 2;
	map->width =  1000;
	map->buf = getmap(str, len, nline);
	if (find_error(map))
	{
		perror("error in map\n");
		exit(1);
	}
	return (0);
}