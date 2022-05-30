/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:44 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 18:28:57 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init(t_map *map)
{
	map->fov = 60;
	init_tex(map);
	return (1);
}

int	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if (strcmp(&av[i], ".cub") == 0)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

void	boot_cub3d(char **av, t_map *map)
{
	if (!check_extension(av[1]))
	{
		perror ("extension file is not compatible");
		free_map(map);
		exit (-1);
	}
	if (!read_map(av[1], map))
	{
		free_map(map);
		exit(-1);
	}
}

void	start_game(t_map *map)
{
	if (!ft_init(map))
	{
		perror("initialization erro ");
		free_window(map);
		exit (1);
	}
	if (!add_text_img(map))
	{	
		perror("texture_error");
		free_window(map);
		exit(1);
	}
	raycaster(map);
}

int	main(int ac, char **av)
{
	t_map	*map;

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
	map->win = mlx_new_window(map->mlx, map->width, map->heigth, "CUB-3D");
	start_game(map);
	mlx_hook(map->win, 2, 0, key_press, map);
	mlx_loop (map->mlx);
	return (0);
}
