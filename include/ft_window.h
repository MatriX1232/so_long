/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:48:04 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 21:09:53 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WINDOW_H
# define FT_WINDOW_H

# include "../so_long.h"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		ft_exit(t_so_long *so_long, int fMap, int fSprite, int fWin);
int		ft_resize(int width, int height, t_so_long *so_long);
int		ft_on_win(t_so_long *so_long, t_point p);
void	ft_gameover_screen(t_so_long *so_long);

void	ft_free_sprites(t_so_long *so_long);
void	ft_free_map(t_so_long *so_long);
void	ft_one_map_free(t_map *map);
void	ft_pimg(void *mlx, void *win, void *img_ptr, t_point p);
int		ft_esc_hook(int keycode, t_so_long *so_long);

#endif
