/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:14:34 by ahaifoul          #+#    #+#             */
/*   Updated: 2022/05/10 11:12:35 by ahaifoul         ###   ########.fr       */
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

int read_map(char* file, t_map *map)
{

    char    *line;
    int     fd;
    int     count;
    char    *str;
    char    *temp;
    
    count = 0;
    initialize_map(map);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        perror("fd error");
    line = get_next_line(fd);
    str = NULL;
    while(line)
    {
        while (line[0] == '\n')
        {
            // free(line);
            line = get_next_line(fd);
        }
        if(strchr(line, ' ') && count < 6)
        {
            if(check_line(line, &map))
                count++;
            else
            {
                perror("ARG FORMAT ERROR/n");
                exit(1);
            }
        }
        else if (count < 6)
        {
            perror("Error arg Elements\n");
            exit(1);
        }
        if (count == 7)
        {
            temp = ft_concat(str, line);
            free(str);
            str = temp;
        }
        if (count == 6)
            count++;
        // free(line);
        line = get_next_line(fd);
    }
    check_map(map, str);
    int x = -1;
    while (map->buf[++x])
        puts(map->buf[x]);
    return (1);
}