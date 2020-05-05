# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 18:36:37 by mgaston           #+#    #+#              #
#    Updated: 2020/05/05 18:36:37 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=	ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c \
		ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isalpha.c ft_isdigit.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_strchr.c \
		ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c

OBJECTS=ft_atoi.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_memchr.o ft_memcpy.o \
		ft_memset.o ft_strlcat.o ft_strlen.o ft_strnstr.o ft_tolower.o ft_bzero.o \
		ft_isalpha.o ft_isdigit.o ft_memccpy.o ft_memcmp.o ft_memmove.o ft_strchr.o \
		ft_strlcpy.o ft_strncmp.o ft_strrchr.o ft_toupper.o

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all