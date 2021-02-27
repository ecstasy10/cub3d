# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsierra- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 12:43:15 by tsierra-          #+#    #+#              #
#    Updated: 2021/01/21 14:49:43 by tsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	cub3d.c \
		fileValidation/fileValidation.c \
		fileValidation/fileConfigValidator.c \
		fileValidation/fileConfig.c \
		utils/errors.c \
		utils/algorithms.c \
		utils/keys.c \
		fileValidation/map.c \
		fileValidation/mapControls.c \
		graphics/map_initialize.c \
		graphics/window_initialize.c \
		graphics/texture_initialize.c \
		graphics/wall_raycast.c \
		graphics/sprite_raycast.c \
		graphics/draw_raycast.c \
		graphics/bitmap.c
SRCDIR = src/
OBJ = $(SRC:.c=.o)
LIBFTDIR = libft/
MLXDIR = mlx/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -I $(LIBFTDIR) -L $(LIBFTDIR) \
		-I $(MLXDIR) -L $(MLXDIR) \
		-lmlx -framework OpenGL -framework AppKit
MAKE = make
RM = rm -f

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(addprefix $(SRCDIR),$(OBJ))
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(addprefix $(SRCDIR),$(SRC)) -o $(NAME) $(CFLAGS) $(LINKS) $(LIBFTDIR)libft.a 

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(addprefix $(SRCDIR),$(OBJ))

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all
