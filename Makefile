# Makefile
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
CPPFLAGS= -Iinclude

EXEC    = push_swap
SRCS    = build_stack.c main.c get_median.c solver.c \
	a_functions.c b_functions.c commands.c
OBJS    = $(SRCS:.c=.o)

LIBFT   = libft/libft.a

all: $(EXEC)

$(EXEC): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $@

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(EXEC)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
