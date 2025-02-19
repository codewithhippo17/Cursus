CFLAGS = -Wall -Wextra -Werror
OTHER_PATHS = ft_printf/libftprintf.a libft/libft.a


all: ft_printf_makefile libft_makefile server client

client:
	cc $(CFLAGS) client.c $(OTHER_PATHS) -o client
server:
	cc $(CFLAGS) server.c $(OTHER_PATHS) -o server

ft_printf_makefile:
	$(MAKE) -C ft_printf

libft_makefile:
	$(MAKE) -C libft

bonus:ft_printf_makefile libft_makefile server_bonus client_bonus

server_bonus:
	gcc $(CFLAGS) server_bonus.c $(OTHER_PATHS) -o server_bonus

client_bonus:
	gcc $(CFLAGS) client_bonus.c $(OTHER_PATHS) -o client_bonus

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f server client
	rm -f server_bonus client_bonus

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all client server ft_printf_makefile libft_makefile bonus server_bonus clean fclean re