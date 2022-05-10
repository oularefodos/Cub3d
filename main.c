/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/09 18:47:28 by ahaifoul         ###   ########.fr       */
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

void    boot_cub3d(char **av)
{
    if (!check_extension(av[1]))
    {
        perror ("extension file is not compatible");
        exit(0);
    }
    if(!read_map(av[1]))
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

    if (ac == 2)
    {
        boot_cub3d(av);
    }
    else
    {
        perror("Error arguments/n");
        exit(0);
    }
}