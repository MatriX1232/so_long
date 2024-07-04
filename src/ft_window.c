/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:47:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/04 12:58:35 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"

int	ft_NULL_HOOK(void *parm)
{
	(void)parm;
	return (0);
}

int	ft_RESIZE(int width, int height, t_so_long *so_long)
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

int	ft_ON_WIN(t_so_long *so_long)
{
	char	*str;
	char	*coins;

	mlx_key_hook(so_long->win, ft_NULL_HOOK, NULL);
	coins = ft_itoa(so_long->coins);
	str = ft_strjoin("SCORE: ", coins);
	mlx_clear_window(so_long->mlx, so_long->win);
	mlx_string_put(so_long->mlx, so_long->win, (so_long->win_width / 2) - 50, (so_long->win_height / 2), 0x00FF00, str);
	free(str);
	free(coins);
	// ft_EXIT(so_long);
	return (0);
}

int	ft_EXIT(t_so_long *so_long)
{
	int	i;

	ft_cprint(CYAN, "Closing window and freeing assets! [0 / 3]\n");

	i = 0;
	while (i < so_long->map->height)
	{
		free(so_long->map->grid[i]);
		free(so_long->backup_map->grid[i]);
		i++;
	}
	free(so_long->map->grid);
	free(so_long->backup_map->grid);
	free(so_long->map);
	free(so_long->backup_map);
	ft_cprint(CYAN, "Map freed! [1 / 3]\n");

	i = 1;
	while (i < 5)
	{
		mlx_destroy_image(so_long->mlx, so_long->sprites[i]->img);
		free(so_long->sprites[i]);
		i++;
	}
	free(so_long->sprites);

	ft_cprint(CYAN, "Sprites freed! [2 / 3]\n");

	mlx_destroy_window(so_long->mlx, so_long->win);

	ft_cprint(CYAN, "Window destroyed! [3 / 3]\n");

	exit(0);

	return (0);
}
