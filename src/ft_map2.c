/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:26:21 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/09 17:02:34 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../include/ft_window.h"

void	ft_move(t_so_long *so_long, t_map *map, int x, int y)
{
	t_point	p_current;

	(void)map;
	so_long->player_pos.x = p_current.x + x;
	so_long->player_pos.y = p_current.y + y;
}

t_map	*ft_map_update(t_so_long *so_long, t_map *map, int x, int y)
{
	char	c;
	t_point	p_current;

	p_current = so_long->player_pos;
	if (p_current.x + x > map->width || p_current.x + x < 0)
		return (map);
	if (p_current.y + y > map->height || p_current.y + y < 0)
		return (map);
	if (map->grid[p_current.y + y][p_current.x + x] == '1')
		return (map);
	c = map->grid[p_current.y + y][p_current.x + x];
	if (c == 'C')
	{
		so_long->coins++;
		so_long->backup_map->grid[p_current.y + y][p_current.x + x] = '0';
	}
	else if (c == 'E')
		ft_on_win(so_long);
	map->grid[p_current.y + y][p_current.x + x] = 'P';
	map->grid[p_current.y][p_current.x] = so_long->\
		backup_map->grid[p_current.y][p_current.x];
	ft_process_map(so_long, map);
	ft_print_coins(so_long);
	return (map);
}

t_map	*ft_copy_map(t_map *dest, t_map *src)
{
	int	y;

	dest = (t_map *) malloc(1 * sizeof(t_map));
	if (!dest)
		return (NULL);
	dest->grid = (char **) malloc(src->height * sizeof(char *));
	if (!dest->grid)
		return (NULL);
	y = 0;
	while (y < src->height)
	{
		dest->grid[y] = ft_substr(src->grid[y], 0, src->width);
		y++;
	}
	dest->width = src->width;
	dest->height = src->height;
	ft_cprint(GREEN, "Map copied successfully!\n");
	return (dest);
}
