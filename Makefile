# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:06:48 by msolinsk          #+#    #+#              #
#    Updated: 2024/06/20 16:33:12 by msolinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXFLAGSO = -I/usr/include -Imlx_linux -O3
MLXFLAGSN = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LINUX

LIBFT_DIR = libft/
MLX_DIR = mlx_linux/
MLX_TRANS = mlx_transparent/
UTILS_DIR = src/utils/

FILES = \
		src/ft_images.c \
		src/ft_draw.c \
		src/ft_colors.c

OBJS = ${FILES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGSO) -c $< -o ${<:.c=.o}

compile_dep:
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	@cp $(MLX_DIR)/libmlx_Linux.a .
	@mv $(MLX_DIR)/libmlx.a .
	@mv $(MLX_DIR)/libmlx_Linux.a .
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv $(LIBFT_DIR)/libft.a .
	@make -C $(MLX_TRANS)
	cp $(MLX_TRANS)/libtransparency.a .
	@mv $(MLX_TRANS)/libtransparency.a .
	echo "\n\n" $(OBJS) "\n\n"

$(NAME): compile_dep $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGSN) so_long.c $(OBJS) libft.a libmlx.a libmlx_Linux.a -o $(NAME)


clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(MLX_TRANS) clean


fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a
	rm -f libmlx_Linux.a
	rm -f libft.a
	rm -f libtransparency.a

re: all

.PHONY: all clean fclean re
