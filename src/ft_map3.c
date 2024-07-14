/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:08:50 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 18:07:08 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../so_long.h"
#include "../libft/libft.h"
#include "../include/ft_file.h"
#include <stdbool.h>

int	ft_ccoins(t_map *map)
{
	int	y;
	int	count;

	y = 0;
	count = 0;
	if (!map)
		return (0);
	while (y < map->height)
	{
		count += ft_count_char('C', map->grid[y]);
		y++;
	}
	ft_cprint(GREEN, "Got number of coins on map!\n");
	return (count);
}

int	ft_check_if_move(t_so_long *so_long, t_map *map, t_point p)
{
	bool	flag;

	flag = false;
	if (so_long->coins != so_long->map->coins)
		flag = true;
	if (map->grid[p.y][p.x] == '1')
		return (1);
	else if (map->grid[p.y][p.x] == 'E' && flag)
		return (1);
	return (0);
}

void	ft_floodfill(t_map *map, t_point p, char c_exit, bool *exit)
{
	if (p.x < 0 || p.y < 0 || p.x >= map->width || p.y >= map->height)
		return ;
	if (map->grid[p.y][p.x] == 'V' || map->grid[p.y][p.x] == '1')
		return ;
	if (map->grid[p.y][p.x] == c_exit)
	{
		ft_debug_log("\t<DEBUG_LOG> <FloodFill> Got exit point\n");
		*exit = True;
		return ;
	}
	map->grid[p.y][p.x] = 'V';
	ft_floodfill(map, (t_point){p.x - 1, p.y}, c_exit, exit);
	ft_floodfill(map, (t_point){p.x + 1, p.y}, c_exit, exit);
	ft_floodfill(map, (t_point){p.x, p.y - 1}, c_exit, exit);
	ft_floodfill(map, (t_point){p.x, p.y + 1}, c_exit, exit);
}

t_point	ft_get_start_point(t_map *map)
{
	int		y;
	t_point	ret;

	y = 0;
	ret.x = 0;
	while (y < map->height)
	{
		ret.y = y;
		if (ft_strchr(map->grid[y], 'P') != NULL)
		{
			ret.x = ft_strchr(map->grid[y], 'P') - map->grid[y];
			break ;
		}
		y++;
	}
	ft_cprint(GREEN, "Got player start point!\n");
	return (ret);
}
