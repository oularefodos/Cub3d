#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
# include "./minilibx_opengl_20191021/mlx.h"


# define SCREENW 1000
# define SCREENH 800

typedef struct info {
    char **no;
    char **so;
    char **we;
    char **ea;
    char **f;
    char **c;
} t_info;

typedef struct data {
    t_info element;
    int player_x;
    int player_y;
    int width;
    int heigth;
    char **buf;
    // struct data *next;
}   t_map;




typedef struct s_data
{
    void	*img;
    void    *img2;
	char	*addr;
    char    *addr2;
    int     counter;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}t_data;

typedef struct s_game
{
    void    *mlx;
    void    *win;

    int     winW;
    int     winH;

    t_map   *mapConfig;
    t_data   dataImage;
}t_game;


//parsing 
int     read_map(char* file, t_map *map);
void    initialize_map(t_map *map);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char  *s2);
char	*ft_strdup(char const *s1);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		str_len(const char *str);
# define BUFFER_SIZE 1000000

// utils
char	**ft_split(const char *s, char c);
char	*ft_strtrim(char *s1, char *set);
char    *ft_concat(char *s1, char *s2);
int check_map(t_map *map, char *str);

 
#endif
