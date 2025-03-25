NAME_1 = server
NAME_2 = client
BONUS_NAME_1 = server_bonus
BONUS_NAME_2 = client_bonus
NAME = $(NAME_1) $(NAME_2)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = server.c \
	helper.c

SRC_1 = client.c \
	helper.c

BONUS_SRC = server_bonus.c \
			helper.c

BONUS_SRC_1 = client_bonus.c \
			helper.c

OBJ = $(SRC:.c=.o)
OBJ_1 = $(SRC_1:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJ_1 = $(BONUS_SRC_1:.c=.o)

all: $(NAME)

$(NAME_1): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME_1)

$(NAME_2): $(OBJ_1)
	$(CC) $(CFLAGS) $(OBJ_1) -o $(NAME_2)

bonus: $(BONUS_NAME_1) $(BONUS_NAME_2)

$(BONUS_NAME_1): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME_1)

$(BONUS_NAME_2): $(BONUS_OBJ_1)
	$(CC) $(CFLAGS) $(BONUS_OBJ_1) -o $(BONUS_NAME_2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_1) $(BONUS_OBJ) $(BONUS_OBJ_1)

fclean: clean
	rm -f $(NAME_1) $(NAME_2) $(BONUS_NAME_1) $(BONUS_NAME_2)

re: fclean all

.PHONY: clean fclean all re bonus