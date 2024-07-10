/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:43:38 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/10 13:06:32 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_game.h"
#include "../so_long.h"
#include <stdlib.h>

void	ft_parse_args(int argc)
{
	if (argc != 2)
	{
		ft_print_error("Bad number of arguments!\n", NULL);
		ft_cprint(RED, "Program takes only one argument!\n");
		ft_cprint(RED, "Usage: ./so_long 'path/to/map.ber'\n");
		exit(1);
	}
	ft_cprint(GREEN, "Parameters correct!\n");
}

void	ft_win_init(t_so_long *so_long, int width, int height)
{
	char	*addr;
	int		bpp;
	int		ll;
	int		ed;

	bpp = 0;
	ll = 0;
	ed = 0;
	addr = NULL;
	so_long->win = mlx_new_window(so_long->mlx, width, height, "SO_LONG GAME");
	so_long->main_img.img = mlx_new_image(so_long->mlx, width, height);
	addr = mlx_get_data_addr(so_long->main_img.img, &bpp, &ll, &ed);
	so_long->main_img.addr = addr;
	so_long->main_img.bits_per_pixel = bpp;
	so_long->main_img.line_length = ll;
	so_long->main_img.endian = ed;
	so_long->main_img.width = width;
	so_long->main_img.height = height;
	so_long->win_width = width;
	so_long->win_height = height;
}
