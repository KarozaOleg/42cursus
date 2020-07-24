# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 17:39:25 by mgaston           #+#    #+#              #
#    Updated: 2020/07/22 22:47:11 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_LIBFT =	libft/ft_atoi.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
				libft/ft_memchr.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_strlcat.c \
				libft/ft_strlen.c libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c \
				libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_memccpy.c libft/ft_memcmp.c \
				libft/ft_memmove.c libft/ft_strchr.c libft/ft_strlcpy.c libft/ft_strncmp.c \
				libft/ft_strrchr.c libft/ft_toupper.c libft/ft_strdup.c libft/ft_calloc.c \
				libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_strmapi.c \
				libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
				libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c \
				libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c \
				libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c \
				libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

OBJECTS_LIBFT = $(SRCS_LIBFT:.c=.o)

SRCS_PRINTF = 	srcs/ft_printf.c \
				srcs/printer.c \
				srcs/return_if.c \
				srcs/parse_patterns.c \
				srcs/printer_c.c \
				srcs/printer_d_i.c \
				srcs/printer_p.c \
				srcs/printer_s.c \
				srcs/printer_u.c \
				srcs/printer_x.c \
				srcs/printer_single_char.c \
				srcs/lenght_of.c \
				srcs/extruder_default.c \
				srcs/handle_default_flag_empty.c \
				srcs/handle_default_flag_minus.c \
				srcs/handle_default_flag_zero.c \
				srcs/is_exist_flag.c \
				srcs/is_exist_flag2.c \
				srcs/handle_d_i_u_x_flag_zero.c

OBJECTS_PRINTF=$(SRCS_PRINTF:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_LIBFT) $(OBJECTS_PRINTF) libft/libft.h
	@ar rc $(NAME) $(OBJECTS_LIBFT) $(OBJECTS_PRINTF)

%.o: %.c libft/libft.h includes/libftprintf.h
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS_LIBFT) $(OBJECTS_PRINTF)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all