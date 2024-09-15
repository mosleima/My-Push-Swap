NAME = push_swap
SRCS = atoi.c\
	cost.c\
	input_tolist.c \
	linkedlist.c \
	main.c \
	move2top.c \
	operations_push.c \
	operations_reverse.c \
	operations_rotate.c \
	operations_swap.c \
	pushing.c \
	split.c \
	target.c \
	util_1.c \
	util_2.c
 
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
