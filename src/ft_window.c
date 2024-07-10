/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:47:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/10 09:30:10 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"

int	ft_null_hook(void *parm)
{
	(void)parm;
	return (0);
}

int	ft_resize(int width, int height, t_so_long *so_long)
{
	write(1, PURPLE, ft_strlen(PURPLE));
	printf("RESIZE:\n");
	printf("FROM: %d x %d\n", so_long->win_width, so_long->win_height);
	printf("TO: %d x %d\n", width, height);
	write(1, END, ft_strlen(END));
	so_long->win_width = width;
	so_long->win_height = height;
	return (0);
}

int	ft_on_win(t_so_long *so_long)
{
	char	*str;
	char	*coins;

	mlx_key_hook(so_long->win, ft_null_hook, NULL);
	coins = ft_itoa(so_long->coins);
	str = ft_strjoin("SCORE: ", coins);
	mlx_clear_window(so_long->mlx, so_long->win);
	mlx_string_put(so_long->mlx, so_long->win, \
		(so_long->win_width / 2) - 50, (so_long->win_height / 2), \
			0x00FF00, str);
	free(str);
	free(coins);
	return (0);
}

int	ft_exit(t_so_long *so_long)
{
	ft_cprint(CYAN, "Closing window and freeing assets! [0 / 3]\n");
	ft_free_map(so_long);
	ft_cprint(CYAN, "Map freed! [1 / 3]\n");
	ft_free_sprites(so_long);
	mlx_destroy_window(so_long->mlx, so_long->win);
	ft_cprint(CYAN, "Window destroyed! [3 / 3]\n");
	exit(0);
	return (0);
}

void	ft_pimg(void *mlx, void *win, void *img_ptr, t_point p)
{
	mlx_put_image_to_window(mlx, win, img_ptr, p.x, p.y);
}
