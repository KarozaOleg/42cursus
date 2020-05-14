# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 18:36:37 by mgaston           #+#    #+#              #
#    Updated: 2020/05/14 14:52:04 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

SRCS=	ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c \
		ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isalpha.c ft_isdigit.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_strchr.c \
		ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_split.c ft_itoa.c ft_putnbr_fd.c

OBJECTS=$(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew.c

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft.h
	@ar rc $(NAME) $(OBJECTS)

%.o: %.c libft.h
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
