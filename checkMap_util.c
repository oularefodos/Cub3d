/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:05:40 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 17:09:10 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pos(char c)
{
	char	*str;
	int		i;

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

int	rem_map(t_map *map, int x, int y)
{
	map->player_x = x;
	map->player_y = y;
	if (map->buf[y][x] == 'E')
		map->player_angle = 0;
	if (map->buf[y][x] == 'S')
		map->player_angle = 90;
	if (map->buf[y][x] == 'W')
		map->player_angle = 180;
	if (map->buf[y][x] == 'W')
		map->player_angle = 270;
	return (1);
}

void	check_space(t_map *map, int x, int y)
{
	if (map->buf[y][0] == '\n')
	{
		perror("error in map\n");
		free(map);
		exit(0);
	}
	if (map->buf[y][x] == 32)
	{
		if (ft_pos(map->buf[y][x + 1]) || (x != 0 && ft_pos(map->buf[y][x - 1]))
				|| (map->buf[y + 1] && ft_pos(map->buf[y + 1][x]))
				|| (y != 0 && ft_pos(map->buf[y - 1][x])))
		{
			perror("error in map\n");
			free(map);
			exit(0);
		}
	}
	if ((map->buf[y][x] != '1' && map->buf[y][x] != ' ')
		&& (!map->buf[y][x + 1] || !x || !y || !map->buf[y + 1]))
	{
		perror("error in map\n");
		free(map);
		exit(0);
	}
}

int	check_rest(t_map *map, int x, int y)
{
	int	n;

	n = 0;
	if (map->buf[y][x] == 'N' || map->buf[y][x] == 'W'
				|| map->buf[y][x] == 'E' || map->buf[y][x] == 'S')
				n += rem_map(map, x, y);
	if (map->buf[y][x] != 'N' && map->buf[y][x] != 'W'
				&& map->buf[y][x] != '0' && map->buf[y][x] != 32
				&& map->buf[y][x] != 'E' && map->buf[y][x] != 'S'
				&& map->buf[y][x] != '1')
	{
		perror("error in map\n");
		free(map);
		exit(0);
	}
	if (n)
		return (n);
	return (0);
}
