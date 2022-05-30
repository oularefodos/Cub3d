/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:10:07 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 19:38:54 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_map *map)
{
	double	x;
	double	y;
	double	angle;

	if (keycode == A_KEY || keycode == D_KEY)
		angle = map->player_angle - 90;
	else
		angle = map->player_angle;
	x = cos(to_radian(angle)) * 0.7;
	y = sin(to_radian(angle)) * 0.7;
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		move_leftright(keycode, map);
	else if ((keycode == W_KEY || keycode == A_KEY)
		&& ft_pos(map->buf[(int)(map->player_y + y)][(int)(map->player_x + x)]))
		move_backforth(keycode, map, x, y);
	else if ((keycode == D_KEY || keycode == S_KEY)
		&& ft_pos (map->buf[(int)(map->player_y - y)][(int)(map->player_x - x)]))
		rotateangle(keycode, map, x, y);
	else if (keycode == ESC_KEY || keycode == Q_KEY)
		close_game(map);
	else
		return (0);
	mlx_clear_window(map->mlx, map->win);
	raycaster(map);
	return (1);
}
