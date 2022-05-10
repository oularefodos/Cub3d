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
    {
         printf("sucess\n");

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

        perror("Error arguments/n");
        exit(1);
    }
    boot_cub3d(av, map);

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
    return (0);
}