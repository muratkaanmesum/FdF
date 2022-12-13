# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:26:25 by mmesum            #+#    #+#              #
#    Updated: 2022/12/13 16:45:33 by mmesum           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
MLX = minilibx_macos/libmlx.a
FRAMEWORK = -framework OpenGL -framework AppKit

GNL = get_next_line/get_next_line.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(GNL)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(GNL) $(FRAMEWORK)
	@echo "FdF is ready"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	@make -C libft
$(MLX):
	@make -C minilibx_macos
$(GNL):
	@make -C get_next_line

clean:
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@make -C minilibx_macos clean
	@make -C get_next_line fclean
	@rm -f $(NAME)

re: fclean all
