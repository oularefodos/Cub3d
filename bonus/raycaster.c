/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:28 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 19:47:00 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3d(t_map *map, double dist, int x, int n)
{
	int		start;
	double	dis;
	double	texpos;
	int		i;

	map->treed.wall_h = floor((double)(map->heigth / 3)
			/ (double)dist);
	start = floor(-map->treed.wall_h / 2 + map->heigth / 2);
	i = 0;
	if (start < 0)
		start = 0;
	if (n)
		dis = (map->player_x + map->ray_x) - (int)(map->player_x + map->ray_x);
	if (n == 0)
		dis = (map->player_y + map->ray_y) - (int)(map->player_y + map->ray_y);
	map->treed.xtex = dis * map->tex[map->i].width;
	map->treed.step = 1.0 * (double)map->tex[map->i].height / map->treed.wall_h;
	if (map->treed.wall_h < map->heigth)
		texpos = 0.0;
	else
		texpos = (map->treed.wall_h / 2 - map->heigth / 2) * map->treed.step;
	draw_floor(map, i, start, x);
	start = draw_walls(map, start, texpos, x);
	draw_cel(map, start, x);
}

void	init_data(t_map *map)
{
	map->planx = 0;
	map->plany = 0.66;
	map->dirx = 0;
	map->diry = -1;
	map->img = mlx_new_image (map->mlx, map->width, map->heigth);
	map->img_buf = (unsigned int *)mlx_get_data_addr
		(map->img, &map->pix, &map->lin, &map->d);
}

void drawmini(t_map *map)
{
	double x;
	double y;
	int oldx;
	int oldy;
	double stepx;
	double stepy;
	int end_x;
	int end_y;

	
	map->img_m = mlx_new_image (map->mlx, 300, 300);
	map->img_buf_m = (unsigned int *)mlx_get_data_addr
		(map->img_m, &map->pix, &map->lin, &map->d);
	x = map->player_x - 10;
	y = map->player_y - 10;
	end_x = map->player_x + 10;
	end_y = map->player_y + 10;
	if (x < 0)
		x = 0;
	if (end_x >= map->buf_w)
		end_x = map->buf_w - 1;
	if (y < 0)
		y = 0;
	if (end_y >= map->buf_h)
		end_y = map->buf_h - 1;
	stepx = (end_x - x) / 300.0;
	stepy = (end_y - y) / 300.0;
	oldy = 0;
	while (oldy < 300)
	{
		oldx = 0;
		x = map->player_x - 10;
		if (x < 0)
		x = 0;
		while (oldx < 300)
		{
			if (map->buf[(int)y][(int)x] == '1')
				map->img_buf_m[oldy * 300 + oldx] = 25215;
			if ((int)map->player_x == (int)x && (int)map->player_y == (int)y)
				map->img_buf_m[oldy * 300 + oldx] = 4000;
			if (map->buf[(int)y][(int)x] == 'P')
				map->img_buf_m[oldy * 300 + oldx] = 16776960;
			oldx++;
			x += stepx;
		}
		y += stepy;
		oldy++;
	}
}

int	start_projection(t_map *map, double ray_angle, int *x)
{
	int	i;
	int	n;
	int v;

	i = 0;
	n = 0;
	v = 0;
	map->ray_x = map->player_x;
	map->ray_y = map->player_y;
	while (ft_pos(map->buf[(int)floor(map->ray_y)][(int)floor(map->ray_x)]))
	{
		if (n)
		{
			map->ray_x += cos(to_radian(ray_angle)) / 566;
			n = 0;
		}
		else
		{
			map->ray_y += sin(to_radian(ray_angle)) / 566;
			n = 1;
		}
		if (map->buf[(int)floor(map->ray_y)][(int)floor(map->ray_x)] == 'P')
		{
			if (sqrt(power(map->ray_x - map->player_x) + power(map->ray_y - map->player_y)) > 1.2 
			&& v == 0)
			{
				*x = 1;
				break;
			}
			else
				v = 1;
		}
	}
	return (n);
}

void	check_rayangle(t_map *map, double ray_angle, int n)
{
	if (cos(to_radian(ray_angle)) < 0 && n == 0)
		map->i = 2;
	else if (cos(to_radian(ray_angle)) > 0 && n == 0)
		map->i = 3;
	if (sin(to_radian(ray_angle)) < 0 && n == 1)
		map->i = 1;
	else if (sin(to_radian(ray_angle)) > 0 && n == 1)
		map->i = 0;
}

int	raycaster(t_map *map)
{
	double	ray_angle;
	int		i;
	int		n;
	int		x;
	double	incre;

	n = 0;
	i = 0;
	move(map);
	init_data(map);
	mlx_clear_window(map->mlx, map->win);
	incre = (double)map->fov / (double)map->width;
	ray_angle = map->player_angle - (map->fov / 2);
	while (i < map->width)
	{
		map->ray_x = map->player_x;
		map->ray_y = map->player_y;
		x = 0;
		n = start_projection(map, ray_angle, &x);
		if (x == 1)
			map->i = 4;
		else
			check_rayangle(map, ray_angle, n);
		map->dist = sqrt(power(map->ray_x - map->player_x)
				+ power(map->ray_y - map->player_y));
		map->dist = map->dist * cos(to_radian(ray_angle - map->player_angle));
		draw3d(map, map->dist, i, n);
		ray_angle += incre;
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	i = map->m % 5;
	map->m++;
	if (map->m == 100000)
		map->m = 1;
	mlx_put_image_to_window(map->mlx, map->win, map->texp[i].img, map->width/1.3 - map->texp[i].width, map->heigth/1.1 - map->texp[i].height);
	drawmini(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img_m, 10, 10);
	return (0);
}
