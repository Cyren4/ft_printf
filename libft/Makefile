# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 10:38:04 by cramdani          #+#    #+#              #
#    Updated: 2020/04/26 12:02:02 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isspace.c\
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strnstr.c\
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
 		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		puissance.c\
		ft_putnbr_base.c\
		ft_atoi_base.c\
		ft_convert_base.c\
		ft_realloc.c\

BONUS	=	ft_lstadd_back.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\

OBJS	= ${SRCS:.c=.o}

BOOBS = ${BONUS:.c=.o}

NAME	=	libft.a
HEADER	=libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADER}


all:	${NAME}

.o :	.c
		${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

${NAME}: 	 ${OBJS}
			ar rc ${NAME} ${OBJS}

bonus: 	 ${OBJS} ${BOOBS}
			ar rc ${NAME} ${OBJS} ${BOOBS}

clean:
		${RM} ${OBJS} ${BOOBS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re 
