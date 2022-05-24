/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:10:07 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/23 13:03:04 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void free_game(t_map *map)
// {

//     mlx_clear_window(map->mlx, map->win);
//     exit(-1);

// }

int key_press(int keycode,t_map *map)
{
	double x;
	double y;

	x = cos(to_radian(map->player_angle)) * 0.5;
	y = sin(to_radian(map->player_angle)) * 0.5;
   	if (keycode == 123)
		map->player_angle -= 10;
	else if (keycode == 124)
		map->player_angle += 10;
	else if (keycode == 13 && ft_pos(map->buf[(int)floor(map->player_y + y)][(int)floor(map->player_x + x)]))//up
	{
			map->player_x += x;
			map->player_y += y;
	}
	else if (keycode == 1 && ft_pos(map->buf[(int)floor(map->player_y - y)][(int)floor(map->player_x - x)]))
	{
			map->player_x -= x;
			map->player_y -= y;
	}
	else 
		return (0);
	mlx_clear_window(map->mlx, map->win);
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