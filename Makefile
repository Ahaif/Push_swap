# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhaifou <abhaifou@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 10:21:20 by abhaifou          #+#    #+#              #
#    Updated: 2025/09/04 10:21:29 by abhaifou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC= -Iinclude

EXEC    = push_swap
SRCS    = build_stack.c main.c get_median.c solver.c \
	a_functions.c b_functions.c commands.c \
	args.c cleanup.c
OBJS    = $(SRCS:.c=.o)

LIBFT   = libft/libft.a

all: $(EXEC)

$(EXEC): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $@

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(EXEC)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
