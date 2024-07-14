/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:50:14 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 20:55:55 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../include/ft_structures.h"
#include "../so_long.h"
#include "../include/get_next_line.h"
#include "../include/ft_window.h"
#include "../include/ft_file.h"

bool	ft_map_swich_main(t_so_long *so_long, t_map *map, int x, int y)
{
	void	*mlx;
	t_point	p;

	mlx = so_long->mlx;
	p.x = x * 100;
	p.y = y * 100;
	if (map->grid[y][x] == '0')
		ft_pimg(mlx, so_long->win, so_long->sprites[0]->img, p);
	else if (map->grid[y][x] == '1')
		ft_pimg(mlx, so_long->win, so_long->sprites[1]->img, p);
	else if (map->grid[y][x] == 'C')
		ft_pimg(mlx, so_long->win, so_long->sprites[2]->img, p);
	else if (map->grid[y][x] == 'E')
		ft_pimg(mlx, so_long->win, so_long->sprites[3]->img, p);
	else if (map->grid[y][x] == 'M')
		ft_pimg(mlx, so_long->win, so_long->sprites[5]->img, p);
	else if (map->grid[y][x] == 'P')
	{
		ft_pimg(mlx, so_long->win, so_long->sprites[4]->img, p);
		so_long->player_pos = (t_point){x, y};
		so_long->backup_map->grid[y][x] = '0';
	}
	return (true);
}

t_map	*ft_load_init(t_so_long *so_long, char *path, int *fd)
{
	t_map	*map;

	*fd = ft_fopen(so_long, path);
	map = NULL;
	map = ft_malloc_map(map, ft_get_map_height(*fd));
	close(*fd);
	map->height = 0;
	*fd = ft_fopen(so_long, path);
	return (map);
}

// 		ft_check_if_player_encountered_monster :)
bool	ft_cipem(t_so_long *so_long, t_point p)
{
	t_map	*map;
	t_point	pl;

	map = so_long->map;
	pl = ft_get_start_point(so_long->map);
	pl = (t_point){pl.x + p.x, pl.y + p.y};
	if (map->grid[pl.y][pl.x] == 'M')
		return (true);
	return (false);
}
