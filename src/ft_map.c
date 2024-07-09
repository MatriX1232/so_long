/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/09 17:21:49 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/ft_map.h"
#include "../include/get_next_line.h"
#include "../include/ft_window.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_print_error(char *error, char *path)
{
	write(1, (char *)RED, ft_strlen(RED));
	write(1, error, ft_strlen(error));
	write(1, path, ft_strlen(path));
	write(1, (char *)END, ft_strlen(END));
	write(1, "\n", 1);
}

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
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = (char **) malloc(ft_get_map_height(fd) * sizeof(char *));
	if (!map->grid)
		return (free(map), NULL);
	map->height = 0;
	close(fd);
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[map->height++] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
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

	mlx = so_long->mlx;
	if (map->grid[y][x] == '0')
		ft_pimg(mlx, so_long->win, so_long->sprites[0]->img, x * 100, y * 100);
	else if (map->grid[y][x] == '1')
		ft_pimg(mlx, so_long->win, so_long->sprites[1]->img, x * 100, y * 100);
	else if (map->grid[y][x] == 'C')
		ft_pimg(mlx, so_long->win, so_long->sprites[2]->img, x * 100, y * 100);
	else if (map->grid[y][x] == 'E')
		ft_pimg(mlx, so_long->win, so_long->sprites[3]->img, x * 100, y * 100);
	else if (map->grid[y][x] == 'P')
	{
		ft_pimg(mlx, so_long->win, so_long->sprites[4]->img, x * 100, y * 100);
		so_long->player_pos.x = x;
		so_long->player_pos.y = y;
		so_long->backup_map->grid[y][x] = '0';
	}
	else
	{
		ft_cprint(RED, "Encountered not supportted character | ");
		ft_printf("%c | %d\n", map->grid[y][x], map->grid[y][x]);
	}
}
