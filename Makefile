# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:06:48 by msolinsk          #+#    #+#              #
#    Updated: 2024/07/10 09:49:07 by msolinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -I./include/

MLXFLAGSO = -I/usr/include -Imlx_linux -O3
MLXFLAGSN = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LINUX -no-pie

LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
MLX_DIR = mlx_linux/

FILES = \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		src/ft_images.c \
		src/ft_draw.c \
		src/ft_colors.c \
		src/ft_map.c \
		src/ft_window.c \
		src/ft_map2.c \
		src/ft_free.c \
		src/ft_game.c \

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
	@echo "$(COLOUR_GREEN)LIBMLX COMPILED SUCCESSFULLY\n$(COLOUR_END)"

	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv $(LIBFT_DIR)/libft.a .
	@echo "$(COLOUR_GREEN)LIBFT COMPILED SUCCESSFULLY\n$(COLOUR_END)"

	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a .
	@mv $(PRINTF_DIR)/libftprintf.a .
	@echo "$(COLOUR_GREEN)FT_PRINTF COMPILED SUCCESSFULLY\n$(COLOUR_END)"
	echo "\n\n" $(OBJS) "\n\n"

$(NAME): compile_dep $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGSN) so_long.c $(OBJS) libft.a libftprintf.a libmlx.a libmlx_Linux.a -o $(NAME)


clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
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
