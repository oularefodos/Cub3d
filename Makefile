NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c get_next_line.c get_next_line_utils.c util.c parser.c utils2.c check_map.c

OBJS = 	$(SRCS:.c=.o)

.c.o:
	$(CC)  $< -o $@

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(NBNS) -o $(NAME)

all:$(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus