/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:33:37 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/12 17:20:25 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_structures.h"
#include "../so_long.h"

void	ft_free_sprites(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		mlx_destroy_image(so_long->mlx, so_long->sprites[i]->img);
		free(so_long->sprites[i]);
		i++;
	}
	free(so_long->sprites);
	ft_cprint(CYAN, "Sprited freed! [2 / 3]\n");
}

void	ft_free_map(t_so_long *so_long)
{
	int	i;

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
}

void	ft_one_map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}
