# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:10:01 by kyacini           #+#    #+#              #
#    Updated: 2022/12/27 21:08:37 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		parsing.c \
		eval_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		utils.c \
		eval_map_way.c


NAME = so_long
CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRC:.c=.o}

all	:	${NAME}

%.o : %.c
	gcc -o $@ -c $< -Wall -Werror -Wextra

so_long	:	${OBJS}
	${MAKE} -C ./libft
	gcc ${OBJS} -o ${NAME} libft/libft.a ${CFLAGS} 

clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf ${NAME}
	
re:	fclean all
