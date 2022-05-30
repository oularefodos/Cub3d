#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <math.h>
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define ESC_KEY 53

# define PI 3.14159265359

#include "mlx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct info {
    char	**no;
    char	**so;
    char	**we;
    char	**ea;
    char	**f;
    char	**c;
} t_info;


typedef struct s_tex
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}t_tex;

typedef struct data {
    t_info			element;
    t_info			texInfo;
    t_tex			tex[5];
	double			ray_x;
	double			ray_y;
	int				fov;
	int				player_angle;
	int				i;
    double			player_x;
    double			player_y;
    int				width;
    int				heigth;
    char			**buf;
    void			*mlx;
    void			*win;
    void			*img;
    unsigned int	*img_buf;

	double 			ray_angle;
	double 			dist;
	double 			dirx;
	double			diry;
	double			planx;
	double			plany;
	int				lin;
	int				pix;
	int				d;
	double			incre;



}   t_map;


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
char	*ft_concat(char *s1, char *s2);
int		check_map(t_map *map, char *str);

//hooks_keys
int     key_press(int keycode,t_map *map);
int     key_release(int keycode, t_map *map);

//texture
int     add_text_img(t_map *map);
char    *rm_bs(char *str);
void    ft_print(t_map *map);


void    raycaster(t_map *map);
double  to_radian(double angle);


void	move_backforwards(t_map *map);
char	*ft_itoa(int n);

int     ft_pos(char c); // check "0NWSN"

void    move_BackForth(int keycode, t_map *map, double x, double y);
void    move_LeftRight(int keycode, t_map *map);
void    rotateAngle(int keycode, t_map *map, double x, double y);
void    close_game(t_map *map);
void    free_map(t_map *map);
void    free_window(t_map *map);


void	init_tex(t_map *map);
void    initialize_map(t_map *map);
void    handle_err(int keyCode, t_map   *map);
int		check_FC(char *line);

char	*free_previous_str(char *str, char *line);
int		fillMap(t_map *map);
int		ft_size(char **spltd);

#endif
