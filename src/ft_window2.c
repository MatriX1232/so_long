/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 19:10:23 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"
#include "../mlx_linux/mlx.h"
#include "../include/ft_structures.h"

void	ft_gameover_screen(t_so_long *so_long)
{
	int		s_x;
	int		s_y;
	t_point	p;

	mlx_destroy_window(so_long->mlx, so_long->win);
	s_x = so_long->sprites[6]->width;
	s_y = so_long->sprites[6]->height;
	so_long->win = mlx_new_window(so_long->mlx, s_x, s_y, "GAME OVER");
	mlx_key_hook(so_long->win, ft_esc_hook, so_long);
	mlx_hook(so_long->win, ON_DESTROY, 0, ft_exit, so_long);
	p.x = 0;
	p.y = 0;
	ft_pimg(so_long->mlx, so_long->win, so_long->sprites[6]->img, p);
}
