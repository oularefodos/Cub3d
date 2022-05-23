/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/22 15:56:26 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void ft_print(t_map *map)
{
    printf("%s\n", map->element.no[0]);
    printf("%s", map->element.no[1]);
    printf("--------------------------\n");
    printf("%s\n", map->element.ea[0]);
    printf("%s", map->element.ea[1]);
    printf("--------------------------\n");
    printf("%s\n", map->element.we[0]);
    printf("%s", map->element.we[1]);
    printf("--------------------------\n");
    printf("%s\n", map->element.so[0]);
    printf("%s", map->element.so[1]);
    printf("--------------------------\n");
    printf("%s\n", map->element.f[0]);
    printf("%s", map->element.f[1]);
    printf("--------------------------\n");
    printf("%s\n", map->element.c[0]);
    printf("%s", map->element.c[1]);
}


void    init_vecSide(t_map *map)
{
    map->vec.x = 0;
	map->vec.y = 0;
	map->vec.deltax = 0;
	map->vec.deltay = 0;
	map->vec.stepx = 0;
	map->vec.stepy = 0;
	map->vec.side = 0;
	map->vec.camx = 0;
	map->vec.mapx = 0;
	map->vec.mapy = 0;
}

void init_tex(t_map *map)
{
    int	j;

	j = -1;
	while (++ j < 4)
	{
		map->tex[j].img = 0;
		map->tex[j].addr = 0;
		map->tex[j].height = 0;
		map->tex[j].width = 0;
	}

}
int ft_init(t_map *map)
{
    
   

    map->fov = 60;
    map->player_angle = 90;
    
	map->move.forw = 0;
	map->move.back = 0;
	map->move.right = 0;
	map->move.left = 0;
	map->move.rotright = 0;
	map->move.rotleft = 0;
    init_vecSide(map);
    init_tex(map);

    return(1);
}


int check_extension(char *av)
{
    int i;
    i = 0;

    while (av[i])
    {
        if (av[i] == '.')
        {
            if (strcmp(&av[i], ".cub") == 0)
                return(1);
            else
                return(0);
        }
        i++;
    }
    return(0);
}

void    boot_cub3d(char **av, t_map *map)
{
    if (!check_extension(av[1]))
    {
        perror ("extension file is not compatible");
        exit(0);
    }
    if(!read_map(av[1], map))
    {
        perror("error inside elements\n");
        exit(0);
    }
}






// void start_game(t_map *map)
// {
    


// }
int main(int ac, char **av)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);

    if (ac != 2)
    { 
        printf("Error arguments/n");
        exit(1);
    }
    boot_cub3d(av, map);
    map->mlx = mlx_init();
     map->win = mlx_new_window ( map->mlx, map->width, map->heigth, "CUB-3D");
    if (!ft_init(map))
        {
            perror("initialization erro ");
            exit(1);
        }
   
    if (!add_text_img(map))
    {
        perror("texture_error");
        exit(1);
    } 


    // for (int y = 0; map->buf[y]; y++)
    // {
    //     for (int x = 0; map->buf[y][x]; x++)
    //     {
    //         if (map->buf[y][x] == '1')
    //         {
    //             for (int i = 0; i < 32; i++)
    //             {
    //                 for (int y = 0; y < 32; y++)
    //                 {
    //                  map->img_buf[i * map->width + y] = 655555552;
    //                 }
    //             }
    //             mlx_put_image_to_window(map->mlx, map->win, map->img, x * 32, y *32);
    //         }
    //     }
    // }
    raycaster(map);
    mlx_hook(map->win, 2, 0, key_press, map);

    // move_backforwards(map);
    // //mlx_loop_hook (drawing 3d)
    // // mlx_hook(map->win, 3, 1L<<1, key_release, map);

    // // start_game(map);
    mlx_loop (map->mlx);
    
   

    return (0);
}
