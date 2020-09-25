# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 14:38:34 by sgirard           #+#    #+#              #
#    Updated: 2020/08/05 11:32:09 by sgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strcmp.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c

OBJS	= ${SRCS:.c=.o}

HEADER	= ./libft.h

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= ar rc
INCLUDE = ./includes
RM	= rm -f

.c.o:
		${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${LFLAGS} ${NAME} ${OBJS}
		ranlib ${NAME}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

PHONY:		all clean fclean re
