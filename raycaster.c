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

	wall_h = floor((double)(map->heigth/2) / (double)dist); //divide by halfheight
	start = floor(map->heigth/2 - wall_h);
	if (n == 0)
		dis = (map->player_x + map->ray_x) - (int)(map->player_x + map->ray_x);
	else
		dis = (map->player_y + map->ray_y) - (int)(map->player_y + map->ray_y);
	xtex = dis * map->tex[3].width;
	step = 1.0 * (double)map->tex[3].height / wall_h;
	texpos = wall_h < map->heigth ? 0 : (wall_h / 2 - map->heigth / 2) * step;
	while (start < floor(map->heigth/2) + wall_h)
	{
		texY = (int)texpos & (map->tex[3].height - 1);
		texpos += step;
		if (start * map->width + x >= map->heigth * map->width)
			break;
		map->img_buf[start * map->width + x] = (unsigned int)map->tex[3].addr[texY * map->tex[3].width + (int)xtex];
		start++;
	}
	while (start < map->heigth)
	{
		if (start * map->width + x >= map->heigth * map->width)
			break;
		map->img_buf[start * map->width + x] = 4745558;
		start++;
	}
}


void	raycaster(t_map *map)
{
	double ray_angle;
	int i;
	double dist;
	int lin; int pix; int d;
	double incre;

	i = 0;
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
			map->ray_x += cos(to_radian(ray_angle)) / 566; // deltax and delta y gride size
			map->ray_y += sin(to_radian(ray_angle)) / 566;
		}
		dist = sqrt(power(map->ray_x - map->player_x) + power(map->ray_y - map->player_y)); //using floor 
		dist = dist * cos(to_radian(ray_angle - map->player_angle));// ?
		draw3d(map, dist, i);
		ray_angle += incre;
		i++;
	}

	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}