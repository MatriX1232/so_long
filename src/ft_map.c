/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 17:59:31 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/ft_map.h"
#include "../include/ft_file.h"
#include "../include/get_next_line.h"
#include "../include/ft_window.h"
#include <fcntl.h>
#include <stdlib.h>

int	ft_get_map_height(int fd)
{
	int		h;
	char	*line;

	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (free(line), h);
		free(line);
		h++;
	}
}

t_map	*ft_load_map(t_so_long *so_long, char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

	line = NULL;
	map = ft_load_init(so_long, path, &fd);
	line = get_next_line(fd);
	if (!line)
	{
		ft_cprint(RED, "Empty map!\n");
		return (ft_exit(so_long, 0, 1, 0), NULL);
	}
	while (line != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[map->height++] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_cprint(GREEN, "Map loaded successfully!\n"), map);
}

void	ft_process_map(t_so_long *so_long, t_map *map)
{
	int	y;
	int	x;

	if (!so_long || !map || !map->grid)
	{
		ft_print_error("Faced ERROR when processing map!", NULL);
		return ;
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '\0')
				break ;
			ft_map_switch(so_long, map, x, y);
			x++;
		}
		y++;
	}
	ft_cprint(GREEN, "Map sprite generated successfully!\n");
}

void	ft_map_switch(t_so_long *so_long, t_map *map, int x, int y)
{
	bool	done;

	done = ft_map_swich_main(so_long, map, x, y);
	if (!done)
	{
		ft_cprint(RED, "Encountered not supportted character | ");
		ft_printf("%c | %d\n", map->grid[y][x], map->grid[y][x]);
	}
}
