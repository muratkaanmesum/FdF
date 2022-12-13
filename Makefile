SRCS = main.c
CC = gcc
NAME			= fdf
RM				= rm -f
CFLAGS = -Wall -Wextra -Werror
next_line_srcs = get_next_line.c get_next_line_utils.c

next_line_objs = $(next_line_srcs:.c=.o)
OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
clean:
	$(RM) $(OBJS)
	make -C minilibx_macos clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

