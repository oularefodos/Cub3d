#include "cub3d.h"

double to_radian(double angle)
{
	return (angle * PI / 180);
}

double power(double x)
{
	return (x * x);
}

void draw3d(t_map *map, double dist, int x, int n)
{
	double wall_h;
	int start, texY;
	double dis;
	double step;
	double texpos;
	double xtex;
	int i;

	wall_h = floor((double)(map->heigth / 3) / (double)dist); //divide by halfheight
	start = floor(-wall_h / 2 + map->heigth / 2);
	i = 0;
	if (start < 0) 
		start = 0;
	if (n)
		dis = (map->player_x + map->ray_x) - (int)(map->player_x + map->ray_x);
	if (n == 0)
		dis = (map->player_y + map->ray_y) - (int)(map->player_y + map->ray_y);
	xtex = dis * map->tex[map->i].width;
	step = 1.0 * (double)map->tex[map->i].height / wall_h;
	texpos = wall_h < map->heigth ? 0 : (wall_h / 2 - map->heigth / 2) * step;
	while (i < start)
	{
		if (i * map->width + x >= map->heigth * map->width)
			break;
		map->img_buf[i * map->width + x] = 12640239;
		i++;
	}
	while (start < wall_h / 2 + map->heigth / 2)
	{
		texY = (int)texpos & (map->tex[map->i].height - 1);
		texpos += step;
		if (start * map->width + x >= map->heigth * map->width)
			break;
		map->img_buf[start * map->width + x] = (unsigned int)map->tex[map->i].addr[texY * map->tex[map->i].width + (int)xtex];
		start++;
	}
	while (start < map->heigth)
	{
		if (start * map->width + x >= map->heigth * map->width || start * map->width + x < 0)
			break;
		map->img_buf[start * map->width + x] = 15454883;
		start++;
	}
}

void	init_data(t_map *map)
{
	map->planx = 0;
	map->plany = 0.66;
	map->dirx = 0;
	map->diry = -1;


}

void	raycaster(t_map *map)
{
	double ray_angle;
	int i, n = 0;
	// double dist, dirx, diry, planx, plany;
	int lin; int pix; int d;
	double incre;

	i = 0;
	init_data(map);
	// planx = 0; plany = 0.66; dirx = 0; diry = -1;
	incre = (double)map->fov / (double)map->width;//distance between rays 
	ray_angle = map->player_angle - (map->fov / 2);// start at 30 degree for the initial ray casting 0 column 
	map->img = mlx_new_image (map->mlx, map->width, map->heigth);
    map->img_buf = (unsigned int *)mlx_get_data_addr (map->img, &pix, &lin, &d);
	while (i < map->width)
	{

		map->ray_x = map->player_x;
    	map->ray_y = map->player_y;
	
		while (ft_pos(map->buf[(int)map->ray_y][(int)map->ray_x])) // ray direction 
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
		}
		if (cos(to_radian(ray_angle)) < 0 && n == 0)
			map->i = 2;
		else if (cos(to_radian(ray_angle)) > 0 && n == 0)
			map->i = 3;
		if (sin(to_radian(ray_angle)) < 0 && n == 1)
			map->i = 1;
		else if (sin(to_radian(ray_angle)) > 0 && n == 1)
			map->i = 0;
		map->dist = sqrt(power(map->ray_x - map->player_x) + power(map->ray_y - map->player_y));
		map->dist = map->dist * cos(to_radian(ray_angle - map->player_angle));// ?// ?
		draw3d(map, map->dist, i, n);
		ray_angle += incre;
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}