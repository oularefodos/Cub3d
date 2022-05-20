/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:10:07 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/20 11:03:48 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void free_game(t_map *map)
{

    mlx_clear_window(map->mlx, map->win);
    exit(-1);

}
 
int key_press(int keycode,t_map *map)
{
   if (keycode == RIGHT_KEY)
		map->player_angle += 10;
	else if (keycode == LEFT_KEY)
		map->player_angle -= 10;
	else  if (keycode == A_KEY && map->buf[map->player_y][map->player_x - 1] != '1')
		map->player_x--;
	else if ((keycode == S_KEY || keycode == DOWN_KEY) && (map->buf[map->player_y + 1][map->player_x] != '1'))
		map->player_y++;
	else if (keycode == D_KEY && map->buf[map->player_y][map->player_x + 1] != '1')
		map->player_x++;
	else if ((keycode == W_KEY || keycode == UP_KEY) && (map->buf[map->player_y - 1][map->player_x] != '1')) 
		map->player_y--;
	else if (keycode == Q_KEY || keycode == ESC_KEY)
		free_game(map);
	else
		return (0);
    raycaster(map);
	return (1);
}

// int	key_release(int keycode, t_map *map)
// {
// 	if (keycode == A_KEY)
// 		map->move.left = 0;
// 	if (keycode == S_KEY || keycode == DOWN_KEY)
// 		map->move.back = 0;
// 	if (keycode == D_KEY)
// 		map->move.right = 0;
// 	if (keycode == W_KEY || keycode == UP_KEY)
// 		map->move.forw = 0;
// 	if (keycode == RIGHT_KEY)
// 		map->move.rotright = 0;
// 	if (keycode == LEFT_KEY)
// 		map->move.rotleft = 0;
// 	return (1);
// }