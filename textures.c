/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:39:10 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/18 17:56:53 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_window(t_map *map)
{
	int	i;

	i = -1;
	printf("Error\nTexture file failed to open\nRetry\n");
	while (++i < 4)
		if (map->tex[i].img)
			mlx_destroy_image(map->mlx, map->tex[i].img);

	// mlx_destroy_display(map->mlx);
	free(map->mlx);
    exit(-1);
	return (0);
}


//converting xpm file to image
int add_text_img(t_map *map)
{

    char    **p[5];
    int     i;
    

    i = -1;


     p[0] = map->texInfo.no;
     p[1] = map->texInfo.so;
     p[2] = map->texInfo.we;
     p[3] = map->texInfo.ea;
     p[4] = 0;

    // while(++i < 5)
    // {

    //     map->tex[i].img = mlx_xpm_file_to_image(map->mlx,p[i][1], &map->tex[i].width, &map->tex[i].height);
    //     if (!map->tex[i].img)
    //         return(free_window(map));
    //     map->tex[i].addr = (int *)mlx_get_data_addr(map->tex[i].img, &map->tex[i].bits_per_pixel, &map->tex[i].line_length, &map->tex[i].endian);   
    //     if (!map->tex[i].addr)
    //         return(free_window(map));
        
    // }
     return(1);
 
    
}

