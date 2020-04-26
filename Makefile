# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 17:16:06 by cramdani          #+#    #+#              #
#    Updated: 2020/04/25 20:47:41 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

HEADER		=	ft_printf.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I${HEADER}

LIBFT_PATH	=	libft

SRCS		=	srcs/ft_printf.c \
				srcs/r_format.c\
				srcs/parsing.c\
				srcs/convert_utils.c\
				srcs/ft_display_char.c\
				srcs/ft_display_int.c \
				srcs/ft_display_uint.c \
				srcs/ft_uint_utils.c \
				srcs/ft_utils.c

OBJS		=	${SRCS:.c=.o}

all :			${NAME}

.c.o :
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} :		${OBJS}
				make -C  ${LIBFT_PATH}
				cp ${LIBFT_PATH}/libft.a ./${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

RM	=			rm -f

clean	:
				${RM} ${OBJS}
				@cd ${LIBFT_PATH} && $(MAKE) clean

fclean:			clean
				${RM} ${NAME}
				@cd ${LIBFT_PATH} && $(MAKE) clean

re:				fclean all

.PHONY:			all clean fclean re

