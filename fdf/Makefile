# Project: fdf
NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

# fdf sources
SRCS = src/parssing.c src/utils.c src/helpers.c
OBJS = $(SRCS:.c=.o)


# includes && libs
INCLUDES = -I/usr/include/minilibx-linux
LIBS = -L./includes/ft_printf -L./includes/libft -L./includes/gnl -L/usr/include/minilibx-linux -lftprintf -lgnl -lft -lmlx

all: gnl ft_printf libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@ -g

gnl:
	make -C includes/gnl

ft_printf:
	make -C includes/ft_printf

libft:
	make -C includes/libft

clean:
	make -C includes/gnl clean
	make -C includes/ft_printf clean
	make -C includes/libft clean
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)
	make -C includes/ft_printf fclean
	make -C includes/libft fclean
	make -C includes/gnl fclean

re: fclean all

.PHONY: all clean fclean re ft_printf libft gnl
