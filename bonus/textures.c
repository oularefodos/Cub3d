/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:10 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/30 19:55:52 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_window_tex(t_map *map)
{
	int	i;

	i = -1;
	printf("Error\nTexture file failed to open\nRetry\n");
	while (++i < 4)
		if (map->tex[i].img)
			mlx_destroy_image(map->mlx, map->tex[i].img);
	free(map->mlx);
	exit(1);
	return (0);
}

char	*rem_bs(char *str)
{
	int		i;
	char	*new;

	i = str_len(str);
	new = malloc(sizeof(char) * i);
	if (!new)
		exit(0);
	i--;
	new[i] = 0;
	while (--i >= 0)
	{
		new[i] = str[i];
	}
	return (new);
}

char	*free_previous_str(char *str, char *line)
{
	char	*temp;

	temp = ft_concat(str, line);
	free(str);
	str = temp;
	return (str);
}

int	fillmap(t_map *map)
{
	int	x;

	x = -1;
	while (map->buf[++x])
		puts(map->buf[x]);
	return (1);
}

//converting xpm file to image
int	add_text_img(t_map *map)
{
	char	*p[11];
	int		i;
	int		y;

	i = 0;
	y = 0;
	p[0] = rem_bs(map->element.no[1]);
	p[1] = rem_bs(map->element.so[1]);
	p[2] = rem_bs(map->element.we[1]);
	p[3] = rem_bs(map->element.ea[1]);
	p[4] = "./textures/door2.xpm";
	p[5] = "./textures/1.xpm";
	p[6] = "./textures/2.xpm";
	p[7] = "./textures/3.xpm";
	p[8] = "./textures/4.xpm";
	p[9] = "./textures/5.xpm";
	p[10] = NULL;
	while (i < 5)
	{
		map->tex[i].img = mlx_xpm_file_to_image
			(map->mlx, p[i], &map->tex[i].width, &map->tex[i].height);
		if (!map->tex[i].img)
			return (free_window_tex(map));
		map->tex[i].addr = (int *)mlx_get_data_addr
			(map->tex[i].img, &map->tex[i].bits_per_pixel,
				&map->tex[i].line_length, &map->tex[i].endian);
		if (!map->tex[i].addr)
			return (free_window_tex(map));
		i++;
	}
	while (i < 10)
	{
		map->texp[y].img = mlx_xpm_file_to_image
			(map->mlx, p[i], &map->texp[y].width, &map->texp[y].height);
		if (!map->texp[y].img)
			return (free_window_tex(map));
		map->texp[y].addr = (int *)mlx_get_data_addr
			(map->texp[y].img, &map->texp[y].bits_per_pixel,
				&map->texp[y].line_length, &map->texp[y].endian);
		if (!map->texp[y].addr)
			return (free_window_tex(map));
		i++;
		y++;
	}
	return (1);
}