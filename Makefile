NAME = libpush_swap.a
EXEC_NAME = push_swap


INCLUDE = include
SRCS = build_stack.c main.c get_median.c solver.c a_functions.c b_functions.c  commands.c 

OBJS :=$(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft $(OBJS) 
	gcc $(CFLAGS) $(OBJS) -Lft_libft -lft -o ${EXEC_NAME}

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

libft:
	cd ft_libft && make && make clean	

clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
