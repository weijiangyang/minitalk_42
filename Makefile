NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft/includes
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_SERVER = src/server.c src/utils.c
SRC_CLIENT = src/client.c src/utils.c
SRC_SERVER_BONUS = src/server_bonus.c src/utils.c 
SRC_CLIENT_BONUS = src/client_bonus.c src/utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

# Compile everything normally
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Normal executables
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

# BONUS: compile server_bonus and client_bonus
bonus: $(LIBFT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER_BONUS) -L$(LIBFT_DIR) -lft
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT_BONUS) -L$(LIBFT_DIR) -lft


# Clean object files
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean


# Clean all + executables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile all
re: fclean all

.PHONY: all clean fclean re bonus
