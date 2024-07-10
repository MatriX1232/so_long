/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/10 09:37:24 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/ft_map.h"
#include "../include/get_next_line.h"
#include "../include/ft_window.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

t_map	*ft_load_map(char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_print_error("ERROR when reading map: ", path), NULL);
	map = NULL;
	map = ft_malloc_map(map, ft_get_map_height(fd));
	map->height = 0;
	close(fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[map->height++] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_cprint(GREEN, "Map loaded successfully!\n");
	return (map);
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
	else if (map->grid[y][x] == 'P')
	{
		ft_pimg(mlx, so_long->win, so_long->sprites[4]->img, p);
		so_long->player_pos = (t_point){x, y};
		so_long->backup_map->grid[y][x] = '0';
	}
	else
	{
		ft_cprint(RED, "Encountered not supportted character | ");
		ft_printf("%c | %d\n", map->grid[y][x], map->grid[y][x]);
	}
}
