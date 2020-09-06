# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 16:13:02 by mgaston           #+#    #+#              #
#    Updated: 2020/09/05 14:38:25 by mgaston          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

# LIBFT
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

# SRCS
SRCS_CUB3D_PARSE = src/parse/parser_base.c

SRCS_CUB3D_PARSE_MAP =	src/parse/map/parser.c \
						src/parse/map/utils.c \
						src/parse/map/validation.c

SRCS_CUB3D_PARSE_SETTINGS = src/parse/settings/parser.c \
							src/parse/settings/parse_resolution.c \
							src/parse/settings/parse_texture.c \
							src/parse/settings/parse_colors.c \
							src/parse/settings/utils.c

SRCS_CUB3D_MLX =	src/mlx/utils.c \
					src/mlx/colors.c \
					src/mlx/functions.c

SRCS_CUB3D =	gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				src/global.c \
				$(SRCS_CUB3D_PARSE) \
				$(SRCS_CUB3D_PARSE_MAP) \
				$(SRCS_CUB3D_PARSE_SETTINGS) \
				$(SRCS_CUB3D_MLX)
				

# INCLUDES
INCLUDES_CUB3D_PARSE =	include/parse/map.h \
						include/parse/parse.h \
						include/parse/settings.h

INCLUDES_CUB3D_MLX =	include/mlx/essences.h \
						include/mlx/functions.h

INCLUDES =	libft/libft.h \
			gnl/get_next_line.h \
			include/cub3d_essences.h \
			include/global.h \
			$(INCLUDES_CUB3D_PARSE) \
			$(INCLUDES_CUB3D_MLX)

OBJECTS_CUB3D=$(SRCS_CUB3D:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_LIBFT) $(OBJECTS_CUB3D) $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS_LIBFT) $(OBJECTS_CUB3D)

%.o: %.c $(INCLUDES)
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS_LIBFT) $(OBJECTS_CUB3D)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all