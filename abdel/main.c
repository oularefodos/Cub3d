/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/17 17:08:01 by ahaifoul         ###   ########.fr       */
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
    else
        printf("sucess\n");
}

int init_game(t_game *game, t_map *map)
{

    game-> mapConfig = map;
    game ->winH = SCREENH;
    game->winW = SCREENW;
    return (1);
}


int    set_window(t_game *game)
{
    game->win = mlx_new_window(game->mlx, game->winW, game->winH, "Start CUB3D");
    if(!game->win)
        perror("mlx win error");
        //free window 
    game->dataImage.img = mlx_new_image(game->mlx, game->winH, game->winW);
    game->dataImage.addr = mlx_get_data_addr(game->dataImage.img, &game->dataImage.bits_per_pixel, &game->dataImage.line_length, &game->dataImage.endian);
    game->dataImage.img2 = mlx_new_image(game->mlx, game->winH, game->winW);
    game->dataImage.addr2 = mlx_get_data_addr(game->dataImage.img2, &game->dataImage.bits_per_pixel, &game->dataImage.line_length, &game->dataImage.endian);
    game->dataImage.counter = 0;
    if (!game->dataImage.img || !game->dataImage.img2 || !game->dataImage.addr || !game->dataImage.addr2)
        perror("image error");
        //free window
    
    return(1);
}

int    start_game(t_map *map)
{
    t_game game;
    int e;
    
    e = init_game(&game, map);
    if (e < 0)
        perror("error init game");
    game.mlx = mlx_init();
    if(!set_window(&game))
        return(0);
    return(1);
}

int main(int ac, char **av)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);

    if (ac != 2)
    { 
        perror("Error arguments/n");
        exit(1);
    }
    boot_cub3d(av, map);
    printf("finishing booting successfuly\n");
    exit(0);
    start_game(map);
    // ft_print(map);
    // free(map);
    return (0);
}
