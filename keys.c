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


void free_game(t_map *map)
{

    mlx_clear_window(map->mlx, map->win);
    exit(-1);

}
 
int key_press(int keycode,t_map *map)
{
	double x;
	double y;
	int newX;
	int newY;
	int D;
	int	E;

	x = cos(to_radian(map->player_angle)) * 0.5;
	y = sin(to_radian(map->player_angle)) * 0.5;
	printf ("%d\n", map->player_angle);
   	if (keycode == 123)
	{
		if (map->player_angle == 0)
			map->player_angle = 360;
		else
			map->player_angle -= 10;
	}
	if (keycode == 124)
	{
		if (map->player_angle == 380)
			map->player_angle = 0;
		else
			map->player_angle += 10;
	}
	if (keycode == W_KEY && map->buf[(int)(map->player_y + y)][(int)(map->player_x + x)] != '1')//up
	{
		D = map->player_x + x;
		E = map-> player_y + y;

		if (map->buf[(int)floor(E)][(int)floor(D)] == '0')
		{
			map->player_x += x;
			map->player_y += y;
		}
	
	}
	if (keycode == S_KEY && map->buf[(int)(map->player_y - y)][(int)(map->player_x - x)] != '1') // down 
	{
		newX = map->player_x - x;
		newY = map-> player_y - y;
		
		if (map->buf[(int)floor(newY)][(int)floor(newX)] == '0')
		{
			map->player_x -= x;
			map->player_y -= y;
		}
		
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