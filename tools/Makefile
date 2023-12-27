SRCS  = ft_atoi_base.c ft_putnbr.c ft_write.c ft_putstr.c shaper.c

OBJS	= ${SRCS:.c=.o}

FLAGS	= -Wall -Wextra -Werror

NAME	= tools.a
HEAD	= ft_tools.h
CC = cc
%.o: %.c ${HEAD}
	@${CC} ${FLAGS} -c $< -o $@

$(NAME):${OBJS}
	@ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
