# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:06:48 by msolinsk          #+#    #+#              #
#    Updated: 2024/04/25 17:14:33 by msolinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx_linux -Lmlx_Linux -lXext -lX11 -lm -lz

LIBFT = libft/
MINILIBX = mlx_linux/

FILES = \
		so_long.c

OBJS = ${FILES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

compile_dep:
	@make -C $(MINILIBX)
	@cp $(MINILIBX)/libmlx.a .
	@cp $(MINILIBX)/libmlx_Linux.a .
	@mv $(MINILIBX)/libmlx.a .
	@mv $(MINILIBX)/libmlx_Linux.a .
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv $(LIBFT)/libft.a .

$(NAME): compile_dep $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) libft.a libmlx.a libmlx_Linux.a -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean


fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a
	rm -f libmlx_Linux.a
	rm -f libft.a

re: all

.PHONY: all clean fclean re
