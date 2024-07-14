/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:47:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 21:03:47 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"
#include "../ft_printf/ft_printf.h"
#include "../include/ft_utils.h"

int	ft_null_hook(void *parm)
{
	(void)parm;
	return (0);
}

int	ft_esc_hook(int keycode, t_so_long *so_long)
{
	if (keycode == 65307)
		ft_exit(so_long, 1, 1, 1);
	return (0);
}

int	ft_on_win(t_so_long *so_long, t_point p)
{
	char	*str;
	char	*coins;
	int		red;
	t_point	pp;

	red = 0x00FF00;
	mlx_clear_window(so_long->mlx, so_long->win);
	mlx_key_hook(so_long->win, ft_null_hook, NULL);
	mlx_key_hook(so_long->win, ft_esc_hook, so_long);
	coins = ft_itoa(so_long->coins);
	str = ft_strjoin_free("SCORE: ", coins, 0, 1);
	pp = (t_point){(so_long->win_width / 2), (so_long->win_height / 2)};
	mlx_string_put(so_long->mlx, so_long->win, pp.x, pp.y, red, str);
	free(str);
	ft_gameover_screen(so_long);
	if (so_long->coins == so_long->map->coins && ft_cipem(so_long, p) == false)
		ft_printf("\n\n%s%sCONGRATULATION, YOU WON!\n", BOLD, GREEN);
	else
		ft_printf("\n\n%s%sGAME OVER, YOU LOOSE\n", BOLD, RED);
	ft_printf("SCORE: %d\n", so_long->coins);
	ft_printf("NUMBER OF MOVES: %d%s\n", so_long->moves, END);
	return (0);
}

int	ft_exit(t_so_long *so_long, int fMap, int fSprites, int fWin)
{
	ft_cprint(CYAN, "Closing window and freeing assets! [0 / 3]\n");
	if (fMap)
		ft_free_map(so_long);
	if (fSprites)
		ft_free_sprites(so_long);
	if (fWin)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		mlx_destroy_display(so_long->mlx);
		ft_cprint(CYAN, "Window destroyed! [3 / 3]\n");
	}
	free(so_long->mlx);
	exit(0);
	return (0);
}

void	ft_pimg(void *mlx, void *win, void *img_ptr, t_point p)
{
	mlx_put_image_to_window(mlx, win, img_ptr, p.x, p.y);
}
