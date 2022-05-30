/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:54:16 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 18:34:27 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_leftright(int keycode, t_map *map)
{
	if (keycode == LEFT_KEY)
	{
		map->player_angle -= 10;
		if (map->player_angle == 0)
			map->player_angle = 360;
	}
	else
	{
		map->player_angle += 10;
		if (map->player_angle == 360)
			map->player_angle = 0;
	}
}

void	move_backforth(int keycode, t_map *map, double x, double y)
{
	if (keycode == W_KEY)
	{
		map->player_x += x;
		map->player_y += y;
	}
	else
	{
		map->player_x += x;
		map->player_y += y;
	}
}

void	rotateangle(int keycode, t_map *map, double x, double y)
{
	if (keycode == D_KEY)
	{
		map->player_x -= x;
		map->player_y -= y;
	}
	else
	{
		map->player_x -= x;
		map->player_y -= y;
	}
}

void	close_game(t_map *map)
{
	free_map(map);
	free_window(map);
	exit(1);
}
