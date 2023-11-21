CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
SRC_SERVER_BONUS = src/server_bonus.c
SRC_CLIENT_BONUS = src/client_bonus.c

GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;35m
BLUE = \033[1;34m
RESET = \033[0m

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@printf "\n$(BLUE)Building $(LIBFT)$(RESET)\n\n"
	@make -C libft --no-print-directory

$(SERVER): $(SRC_SERVER)
	@$(CC) $(CFLAGS) $(SRC_SERVER) -Llibft -lft -o $(SERVER)
	@printf "\n$(CYAN)Creating $(SERVER)$(RESET)\n\n"

$(CLIENT): $(SRC_CLIENT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) -Llibft -lft -o $(CLIENT)
	@printf "\n$(CYAN)Creating $(CLIENT)$(RESET)\n\n"

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SRC_SERVER_BONUS)
	@$(CC) $(CFLAGS) $< -Llibft -lft -o $@
	@printf "\n$(CYAN)Creating $(SERVER_BONUS)$(RESET)\n\n"

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $< -Llibft -lft -o $@
	@printf "\n$(CYAN)Creating $(CLIENT_BONUS)\n\n"

clean:
	@make -C libft clean --no-print-directory

fclean: clean
	@make -C libft fclean --no-print-directory
	@printf "$(RED)Cleaning $(SERVER)$(RESET)\n"
	@printf "$(RED)Cleaning $(CLIENT)$(RESET)\n"
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@rm -f $(SERVER_BONUS)
	@rm -f $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
