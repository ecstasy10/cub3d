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
		fileValidation.c \
		fileConfigValidator.c \
		fileConfig.c \
		errors.c \
		utils/stack.c\
		map.c \
		player.c
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
