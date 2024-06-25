/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/25 13:27:04 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/ft_map.h"
#include "../include/get_next_line.h"
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
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
// t_map	*ft_load_map(char *path)
// {
// 	int		fd;
// 	char	*line;
// 	t_map	*map;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		fprintf(stderr, "ERROR when reading map: %s: %s\n", path, strerror(errno));
// 		return (ft_print_error("ERROR when reading map: ", path), NULL);
// 	}
// 	map = (t_map *) malloc(1 * sizeof(t_map));
// 	if (!map)
// 		return (NULL);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (free(line), NULL);
// 	map->width = ft_strlen(line);
// 	map->height = 1;
// 	while (line != NULL)
// 	{
// 		map->grid[map->height] = line;
// 		line = get_next_line(fd);
// 		(map->height)++;
// 	}
// 	close(fd);
// 	return (map);
// }

t_map *ft_load_map(char *path)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "ERROR when reading map: %s: %s\n", path, strerror(errno));
		return (ft_print_error("ERROR when reading map: ", path), NULL);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = (char **)malloc(ft_get_map_height(fd) * sizeof(char *));
	if (!map->grid)
		return (free(map), NULL);
	map->height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line);
		if (map->height >= grid_size)
		{
			grid_size *= 2;
			char **new_grid = realloc(map->grid, grid_size * sizeof(char *));
			if (!new_grid)
			{
				for (i = 0; i < map->height; i++)
					free(map->grid[i]);
				return (free(map->grid), free(map), NULL);
			}
			map->grid = new_grid;
		}
		map->grid[map->height] = line;
		map->height++;
	}
	close(fd);
	return map;
}

// void	ft_process_map(t_so_long *so_long, t_map *map)
// {
// 	int	y;
// 	int	x;

// 	if (!so_long || !map)
// 		return (ft_print_error("Faced ERROR when processing map!", NULL), NULL);
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->grid)
// 		{
// 			switch (map->grid[y][x])
// 			{
// 			case '1':
// 				put_img_to_img()
// 				break;

// 			default:
// 				break;
// 			}
// 		}
// 	}

// }
