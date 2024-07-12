/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:26:21 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/12 18:14:50 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../include/ft_window.h"
#include "../include/ft_file.h"

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
	if (ft_check_if_move(so_long, map, (t_point){p_current.x + x, p_current.y + y}))
		return (map);
	c = map->grid[p_current.y + y][p_current.x + x];
	if (c == 'C')
	{
		so_long->coins++;
		so_long->backup_map->grid[p_current.y + y][p_current.x + x] = '0';
	}
	else if ((c == 'E' && so_long->coins == so_long->map->coins)|| c == 'M')
		ft_on_win(so_long);
	so_long->moves++;
	map->grid[p_current.y + y][p_current.x + x] = 'P';
	map->grid[p_current.y][p_current.x] = so_long->\
		backup_map->grid[p_current.y][p_current.x];
	ft_process_map(so_long, map);
	ft_print_ui(so_long);
	return (map);
}

int	ft_check_map(t_map *map)
{
	int	y;
	int	c_ex;
	int	c_pl;

	y = 0;
	if (ft_count_char('1', map->grid[0]) != map->width)
		return (ft_debug_log("Map is not closed!\n"), 0);
	if (ft_count_char('1', map->grid[map->height - 1]) != map->width)
		return (ft_debug_log("Map is not closed!\n"), 0);
	c_ex = 0;
	c_pl = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			return (ft_debug_log("Map is not closed!\n"), 0);
		if ((int)ft_strlen(map->grid[y]) != map->width)
			return (ft_debug_log("Map is not rectangular!\n"), 0);
		c_ex += ft_count_char('E', map->grid[y]);
		c_pl += ft_count_char('P', map->grid[y]);
		y++;
	}
	if (c_ex != 1 || c_pl != 1)
		return (ft_debug_log("Number of player or exits is not 1\n"), 0);
	return (1);
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
	dest->coins = src->coins;
	ft_cprint(GREEN, "Map copied successfully!\n");
	return (dest);
}

t_map	*ft_malloc_map(t_map *map, int height)
{
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = (char **) malloc(height * sizeof(char *));
	if (!map->grid)
		return (free(map), NULL);
	map->coins = 0;
	return (map);
}
