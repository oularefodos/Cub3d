/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/10 11:13:33 by ahaifoul         ###   ########.fr       */
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


void ft_init(t_map *map)
{
    int pix = 0;
    int lin = 0;
    int d = 0;
    map->mlx = mlx_init();
    map->win = mlx_new_window ( map->mlx, map->width, map->heigth, "CUB-3D");
    map->img = mlx_new_image (map->mlx, map->width, map->heigth);
    map->img_buf = (unsigned int *)mlx_get_data_addr (map->img, &pix, &lin, &d);
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
    ft_init(map);
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
    //                  map->img_buf[i * map->width + y] = 6552;
    //                 }
    //             }
    //             mlx_put_image_to_window(map->mlx, map->win, map->img, x * 32, y *32);
    //         }
    //     }
    // }
    mlx_loop (map->mlx);
    return (0);
}
