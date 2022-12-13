SRCS = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME			= fdf
RM				= rm -f

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

