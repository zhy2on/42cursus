# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 18:03:00 by jihoh             #+#    #+#              #
#    Updated: 2021/05/14 18:03:27 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_bzero.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c
OBJS = ${SRCS:.c=.o}

TARGET = libft.a

all: ${TARGET}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

${TARGET}: ${OBJS}
	ar -cr $@ $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${TARGET}

re: fclean all
