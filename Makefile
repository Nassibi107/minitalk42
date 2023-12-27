
NAME  = mintalk.a
CLIENT	=	client
SERVER	=	server


SRC_P  = Producer.c
OBJ_P	= Producer.o
SRC_C = Consumer.c utlis_server.c
OBJ_C = Consumer.o utlis_server.o

FLAGS	= -Wall -Wextra -Werror

TOOLS	=	tools/tools.a
TOOLS_DIR	=	tools
INC		=	minitalk.h
CC = gcc
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
OK	=	[$(GREEN)SUCCESS$(RESET)]
NO	=	[$(YELLOW)INFO$(RESET)]

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@


all: $(TOOLS)  $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_C) $(INC)
	@$(CC) $(FLAGS) $(TOOLS) -o $@  $(OBJ_C)
	@printf "$(OK) server ready.\n"

$(CLIENT): $(OBJ_P) $(INC)
	@ $(CC) $(FLAGS) $(TOOLS) -o $@ $(OBJ_P)
	@printf "$(OK) client ready.\n"

$(TOOLS):
	@ $(MAKE) -C $(TOOLS_DIR)


clean:
	@ $(MAKE) clean -C $(TOOLS_DIR)
	@ $(RM) $(OBJ_P) $(OBJ_C)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(TOOLS_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all
.PHONY: all clean fclean re
