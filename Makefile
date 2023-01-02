#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _
# ___ __|  __/   |   |  (   |    <    __/
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := fdf
CC        := gcc
FLAGS    := -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_Printf/ft_printf.c \
                          ft_Printf/ft_putnbr_base.c \
                          ft_Printf/handle_numbers.c \
                          ft_Printf/libft/ft_atoi.c \
                          ft_Printf/libft/ft_bzero.c \
                          ft_Printf/libft/ft_calloc.c \
                          ft_Printf/libft/ft_isalnum.c \
                          ft_Printf/libft/ft_isalpha.c \
                          ft_Printf/libft/ft_isascii.c \
                          ft_Printf/libft/ft_isdigit.c \
                          ft_Printf/libft/ft_isprint.c \
                          ft_Printf/libft/ft_itoa.c \
                          ft_Printf/libft/ft_lstadd_back.c \
                          ft_Printf/libft/ft_lstadd_front.c \
                          ft_Printf/libft/ft_lstclear.c \
                          ft_Printf/libft/ft_lstdelone.c \
                          ft_Printf/libft/ft_lstiter.c \
                          ft_Printf/libft/ft_lstlast.c \
                          ft_Printf/libft/ft_lstmap.c \
                          ft_Printf/libft/ft_lstnew.c \
                          ft_Printf/libft/ft_lstsize.c \
                          ft_Printf/libft/ft_memchr.c \
                          ft_Printf/libft/ft_memcmp.c \
                          ft_Printf/libft/ft_memcpy.c \
                          ft_Printf/libft/ft_memmove.c \
                          ft_Printf/libft/ft_memset.c \
                          ft_Printf/libft/ft_putchar_fd.c \
                          ft_Printf/libft/ft_putendl_fd.c \
                          ft_Printf/libft/ft_putnbr_fd.c \
                          ft_Printf/libft/ft_putstr_fd.c \
                          ft_Printf/libft/ft_split.c \
                          ft_Printf/libft/ft_strchr.c \
                          ft_Printf/libft/ft_strdup.c \
                          ft_Printf/libft/ft_striteri.c \
                          ft_Printf/libft/ft_strjoin.c \
                          ft_Printf/libft/ft_strlcat.c \
                          ft_Printf/libft/ft_strlcpy.c \
                          ft_Printf/libft/ft_strlen.c \
                          ft_Printf/libft/ft_strmapi.c \
                          ft_Printf/libft/ft_strncmp.c \
                          ft_Printf/libft/ft_strnstr.c \
                          ft_Printf/libft/ft_strrchr.c \
                          ft_Printf/libft/ft_strtrim.c \
                          ft_Printf/libft/ft_substr.c \
                          ft_Printf/libft/ft_tolower.c \
                          ft_Printf/libft/ft_toupper.c \
                          Get_Next_Line/get_next_line.c \
                          Get_Next_Line/get_next_line_utils.c \
                          get_map.c \
                          main.c \
                          check_map.c \
                            render_map.c \
                            utils.c \
                            get_points.c \
                            matrices.c \
                            get_modified_points.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


