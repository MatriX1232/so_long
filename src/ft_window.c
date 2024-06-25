/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:47:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/25 12:43:06 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_window.h"

int	ft_EXIT(t_so_long *so_long)
{
	printf("Closing window and freeing assets!\n");

	mlx_destroy_image(so_long->mlx, so_long->sprites[1]->img);
	free(so_long->sprites[1]);
	mlx_destroy_image(so_long->mlx, so_long->sprites[4]->img);
	free(so_long->sprites[4]);

	printf("All assets freed!\n");

	mlx_destroy_window(so_long->mlx, so_long->win);

	exit(0);

	return (0);
}
