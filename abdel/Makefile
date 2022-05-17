NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx_opengl_20191021/libmlx.a
LIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c get_next_line.c get_next_line_utils.c util.c parser.c utils2.c check_map.c

OBJS = 	$(SRCS:.c=.o)

.c.o:
	$(CC) -g -Imlx -c $< -o $@

$(NAME): $(SRCS) $(MLX)
	$(CC) $(SRCS) $(CFLAGS) $(LIB)  -o $(NAME)

all:$(NAME)

$(MLX):
	$(MAKE) -C ./mlx

clean:
	@rm -f $(OBJS)
	@cd minilibx_opengl_20191021 && make clean


fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus