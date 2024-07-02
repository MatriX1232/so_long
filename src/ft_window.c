/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:47:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/02 19:32:52 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"

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

int	ft_EXIT(t_so_long *so_long)
{
	int	i;

	ft_cprint(CYAN, "Closing window and freeing assets!\n");

	i = 0;
	while (i < so_long->map->height)
	{
		free(so_long->map->grid[i]);
		i++;
	}
	free(so_long->map->grid);
	free(so_long->map);
	ft_cprint(CYAN, "Map freed!\n");

	i = 1;
	while (i < 5)
	{
		mlx_destroy_image(so_long->mlx, so_long->sprites[i]->img);
		free(so_long->sprites[i]);
		i++;
	}
	free(so_long->sprites);

	ft_cprint(CYAN, "Sprites freed!\n");

	mlx_destroy_window(so_long->mlx, so_long->win);

	ft_cprint(CYAN, "Window destroyed!\n");

	exit(0);

	return (0);
}
