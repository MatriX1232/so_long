/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:12:24 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/01 11:29:44 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

# include "include/ft_map.h"
# include "include/ft_structures.h"

// minimal color codes
# define END "\x1b[0m"
# define BOLD '\x1b[1m'
# define UNDER '\x1b[4m'
# define REV '\x1b[7m'
# define GREY '\x1b[30m'
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW '\x1b[33m'
# define BLUE '\x1b[34m'
# define PURPLE "\x1b[35m"
# define CYAN '\x1b[36m'
# define WHITE '\x1b[37m'

# define BPX 100

// typedef struct s_Color
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	a;
// }	t_Color;

// typedef struct s_sprite
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		width;
// 	int		height;
// 	int		endian;
// }	t_sprite;

// enum e_action
// {
// 	MOVE,
// 	UI
// };

// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// }	t_point;

// typedef struct s_queue
// {
// 	enum e_action	action;
// 	t_sprite		*sprite;
// 	t_point			begin;
// 	t_point			dest;
// }	t_queue;

// typedef struct s_so_long
// {
// 	void		*mlx;
// 	void		*win;
// 	t_sprite	main_img;
// 	t_queue		queue;
// 	t_map		*map;
// 	t_sprite	**sprites;
// }	t_so_long;

void			ft_print_img_info(t_sprite *img);
t_sprite		*xpm_load_image(void *mlx, char *path);
t_sprite		**ft_load_sprites(void *mlx);
t_sprite		**ft_malloc_sprites(void);

void			put_pixel_img(t_sprite *img, int x, int y, int color);
void			put_img_to_img(t_sprite *dst, t_sprite *src, int x, int y);
unsigned int	get_pixel_img(t_sprite *img, int x, int y);

t_Color			blend(t_Color src, t_Color dst);
t_Color			int_to_color(int color);
int				color_to_int(t_Color color);

void			ft_cprint(char *color, char *str);

#endif
