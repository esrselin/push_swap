NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    = ps_parse.c ps_parse_utils.c ps_utils.c ps_swap.c  ps_rotate.c\
			ps_push.c ps_revrotate.c ps_index_sort.c push_swap.c ps_rotate_stacks.c\
			ps_sort.c ps_position.c ps_chunk_sort.c
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
INCS      = -I . -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
