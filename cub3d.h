#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>

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
}   t_map;

// matrix 
#endif
