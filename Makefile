CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SERVER = server
CLIENT = client
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
BLUE = \033[1;34m


RESET = \033[0m



.PHONY: all clean fclean re

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@printf "\n$(BLUE)Building $(LIBFT)$(RESET)\n\n"
	@make -C libft --no-print-directory

$(SERVER): $(SRC_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_SERVER) -Llibft -lft -o $(SERVER)
	@printf "\n$(CYAN)Creating $(SERVER)$(RESET)\n\n"

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) -Llibft -lft -o $(CLIENT)
	@printf "\n$(CYAN)Creating $(CLIENT)$(RESET)\n\n"


clean:
	@make -C libft clean --no-print-directory

fclean: clean
	@make -C libft fclean --no-print-directory
	@printf "$(RED)Cleaning $(SERVER)$(RESET)\n"
	@printf "$(RED)Cleaning $(CLIENT)$(RESET)\n"
	@rm -f $(SERVER)
	@rm -f $(CLIENT)

re: fclean all