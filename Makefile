NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  push_swap.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)
$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re