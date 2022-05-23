/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:44:19 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/21 10:54:50 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_backforwards(t_map *map)
{
    int x;
    int y;
    int D;
    int E;

    x = cos(to_radian(map->player_angle)) * 0.5;
	y = sin(to_radian(map->player_angle)) * 0.5;

    if (map->move.forw)
    {
        D = map->player_x + x;
		E = map-> player_y + y;

		if (map->buf[(int)floor(E)][(int)floor(D)] == '0')
		{
			map->player_x += x;
			map->player_y += y;
		}
    }
    if (map->move.back)
    {
            D = map->player_x - x;
	        E = map-> player_y - y;
		
		if (map->buf[(int)floor(D)][(int)floor(E)] == '0')
		{
			map->player_x -= x;
			map->player_y -= y;
		}
		
    }
        
}