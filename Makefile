# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 17:16:06 by cramdani          #+#    #+#              #
#    Updated: 2020/04/30 01:25:00 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

HEADER		=	ft_printf.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror 

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

BONUS	=	

OBJS		=	${SRCS:.c=.o}

BOOBS		=	${BONUS:.c=.o}

all :			${NAME}

.c.o :
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} :		${OBJS}
				make -C  ${LIBFT_PATH}
				cp ${LIBFT_PATH}/libft.a ./${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

RM	=			rm -f

bonus	: 	 all ${BOOBS}
			ar rc ${NAME} ${OBJS} ${BOOBS}

clean	:
				${RM} ${OBJS}
				@cd ${LIBFT_PATH} && $(MAKE) clean

fclean:			clean
				${RM} ${NAME}
				@cd ${LIBFT_PATH} && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re

