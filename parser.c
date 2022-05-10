/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:34 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/10 10:07:29 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>


int ft_size(char **spltd)
{
    int i;

    i = 0;
    while(spltd[i])
        i++;
    return(i);
}

void    initialize_map(t_map *map)
{
     
    map->element.no = 0;
    map->element.ea = 0;
    map->element.so = 0;
    map->element.we = 0;
    map->element.f = 0;
    map->element.c = 0;
    map->heigth = 0;
    map->width = 0;
    map->player_x = 0;
    map->player_y = 0;
}

int    check_FC(char *line)
{
    if (line[0] == 'F' || line[0] == 'C')
        return(1);
    else
        return(0);
}


void    assign_data(t_map **map, char **spltd)
{
    
 
    if (strcmp(spltd[0], "NO") == 0)
        (*map)->element.no = spltd;
    else if (strcmp(spltd[0], "SO") == 0)
        (*map)->element.so = spltd;
    else if (strcmp(spltd[0], "WE") == 0)
        (*map)->element.we = spltd;
    else if (strcmp(spltd[0], "EA") == 0)
        (*map)->element.ea = spltd;
    else 
    {
        if(spltd[0][0] == 'F')
            (*map)->element.f = spltd;
        else if(spltd[0][0] == 'C')
            (*map)->element.c = spltd;   
    }
      
    
}

int    check_line(char *line, t_map **map)
{
    int j;
    char **spltd;



    if (strchr(line, ' '))
    {
        spltd = ft_split(line, ' ');
        j = ft_size(spltd);
       
        if ((strcmp(spltd[0], "NO") == 0 || strcmp(spltd[0], "SO") == 0 
        || strcmp(spltd[0], "WE") == 0 || strcmp(spltd[0], "EA") == 0
        || (check_FC(spltd[0])) ) && (j == 2))
        {
            assign_data(map, spltd);
            return(1);

        }
    }
    return (0);   
}

int read_map(char* file)
{

    char    *line;
    int     fd;
    int     count;
    t_map *map;

     count = 0;

    map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
    
    initialize_map(map);

    fd = open(file, O_RDONLY);
    if (fd < 0)
        perror("fd error");
    line = get_next_line(fd);
    while(line)
    {
        // if (line[0] == '\n')
        //     continue;
        if(strchr(line, ' '))
        {
            if(check_line(line, &map))
                count++;
            else
            {
                perror("ARG FORMAT ERROR/n");
                exit(0);
            }
        }
        else
        {
            perror("Error arg Elements\n");
            exit(0);
        }
        // if (count == 6)
        // {
        //     //start handling map 
        // }
        line = get_next_line(fd);
    }
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
            printf("--------------------------\n");

    return(1);
}