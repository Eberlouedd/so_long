# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:10:01 by kyacini           #+#    #+#              #
#    Updated: 2022/12/28 19:58:45 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/main.c \
		src/parsing.c \
		src/eval_map.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \
		src/utils.c \
		src/eval_map_way.c \
		src/errors.c \
		src/graphics.c \
		src/hook.c

OBJS =	objs/main.o \
		objs/parsing.o\
		objs/eval_map.o\
		gnl/get_next_line.o\
		gnl/get_next_line_utils.o\
		objs/utils.o\
		objs/errors.o\
		objs/eval_map_way.o \
		objs/graphics.o \
		objs/hook.o

NAME = so_long

CC = gcc

INC = include/

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFLAGS = -L libft -lft

all : ${NAME}

objs/%.o : src/%.c
	mkdir -p ./objs
	$(CC)  -I${INC} -c $< -o $@

%.o : %.c
	$(CC)  -I${INC} -c $< -o $@

${NAME} : ${OBJS} $(LIB)
	make -C ./libft
	make -C ./mlx_linux
	$(CC) ${OBJS} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME}

clean:
		$(RM) ${OBJS} $(OBJ_B)
		$(RM) ./objs
		make clean -C ./mlx_linux
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) ./mlx_linux/libmlx_Linux.a
		$(RM) ./mlx_linux/libmlx.a
		$(RM) ./libft/libft.a

re:	fclean all

.PHONY:        all clean fclean re