# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 16:13:02 by mgaston           #+#    #+#              #
#    Updated: 2020/11/22 14:33:45 by mgaston          ###   ########.fr        #
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

SRCS_CUB3D_SETTINGS =	src/settings/parser.c \
						src/settings/parse_resolution.c \
						src/settings/parse_texture.c \
						src/settings/parse_colors.c \
						src/settings/utils.c

SRCS_CUB3D_MAP =	src/map/parser.c \
					src/map/utils.c \
					src/map/validation.c

SRCS_CUB3D_MLX =	src/mlx/utils.c \
					src/mlx/colors.c \
					src/mlx/draw.c \
					src/mlx/hooks.c

SRCS_CUB3D_PLAYER = src/player/utils.c

SRCS_CUB3D_SPRITES = src/sprite/utils.c

SRCS_CUB3D_GAME = src/game/utils.c

SRCS_CUB3D_TEXTURE = src/texture/utils.c

SRCS_CUB3D_RAY_CASTING = src/ray_casting/utils.c

SRCS_CUB3D =	gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				src/global.c \
				$(SRCS_CUB3D_PARSE) \
				$(SRCS_CUB3D_SETTINGS) \
				$(SRCS_CUB3D_MAP) \
				$(SRCS_CUB3D_MLX)  \
				$(SRCS_CUB3D_PLAYER) \
				$(SRCS_CUB3D_SPRITES) \
				$(SRCS_CUB3D_GAME) \
				$(SRCS_CUB3D_TEXTURE) \
				$(SRCS_CUB3D_RAY_CASTING)
				

# INCLUDES
INCLUDES_CUB3D_PARSE =	include/parse/parse.h

INCLUDES_CUB3D_SETTINGS = include/settings/settings_utils.h

INCLUDE_CUB3D_MAP =		include/map/map_essences.h \
						include/map/map_utils.h

INCLUDES_CUB3D_MLX =	include/mlx/mlx_essences.h \
						include/mlx/mlx_utils.h \
						include/mlx/draw.h \
						include/mlx/colors.h \
						include/mlx/hooks.h

INCLUDES_CUB3D_PLAYER =	include/player/player_essences.h \
						include/player/player_utils.h

INCLUDES_CUB3D_SPRITES =	include/sprite/sprite_essence.h \
							include/sprite/sprite_utils.h

INCLUDES_CUB3D_GAME =	include/game/game_essences.h \
						include/game/game_utils.h

INCLUDES_CUD3B_TEXTURE =	include/texture/texture_essence.h \
							include/texture/texture_utils.h

INCLUDES_CUB3D_RAY_CASTING = 	include/ray_casting/ray_casting_utils.h \
								include/ray_casting/ray_casting_essences.h

INCLUDES =	libft/libft.h \
			gnl/get_next_line.h \
			include/global.h \
			include/global_essences.h \
			$(INCLUDES_CUB3D_PARSE) \
			$(INCLUDE_CUB3D_MAP) \
			$(INCLUDES_CUB3D_MLX) \
			$(INCLUDES_CUB3D_PLAYER) \
			$(INCLUDES_CUB3D_SPRITES) \
			$(INCLUDES_CUB3D_GAME) \
			$(INCLUDES_CUD3B_TEXTURE) \
			$(INCLUDES_CUB3D_RAY_CASTING)

OBJECTS_CUB3D=$(SRCS_CUB3D:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_LIBFT) $(OBJECTS_CUB3D) $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS_LIBFT) $(OBJECTS_CUB3D)

test: $(NAME)
	@gcc test*.c -g cub3d.a -framework OpenGL -framework AppKit -Lminilibx_mms -lmlx -Iminilibx_mms libmlx.dylib

test2: $(NAME)
	@gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm

%.o: %.c $(INCLUDES)
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS_LIBFT) $(OBJECTS_CUB3D)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all