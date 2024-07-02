/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:24:04 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/02 18:01:34 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTURES_H
# define FT_STRUCTURES_H

enum e_blocks
{
	EMPTY,
	WALL,
	COLLECTABLE,
	EXIT,
	PLAYER,
	ENEMY
};

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_Color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_Color;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
	char	*path;
}	t_sprite;

enum e_action
{
	MOVE,
	UI
};

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_queue
{
	enum e_action	action;
	t_sprite		*sprite;
	t_point			begin;
	t_point			dest;
}	t_queue;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_sprite	main_img;
	t_queue		queue;
	t_map		*map;
	t_sprite	**sprites;
	t_point		player_pos;
}	t_so_long;

#endif
