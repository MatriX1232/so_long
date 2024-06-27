/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/27 10:36:24 by msolinsk         ###   ########.fr       */
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
	// int		i;
	// int		grid_size;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "ERROR when reading map: %s: %s\n", path, strerror(errno));
		return (ft_print_error("ERROR when reading map: ", path), NULL);
	}
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = (char **) malloc(ft_get_map_height(fd) * sizeof(char *));
	if (!map->grid)
		return (free(map), NULL);
	map->height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line);
		map->grid[map->height] = line;
		map->height++;
		printf("<MAP> | Width: %d | Height: %d\n", map->width, map->height);
		// if (map->height >= grid_size)
		// {
		// 	char **new_grid = realloc(map->grid, grid_size * sizeof(char *));
		// 	if (!new_grid)
		// 	{
		// 		for (i = 0; i < map->height; i++)
		// 			free(map->grid[i]);
		// 		return (free(map->grid), free(map), NULL);
		// 	}
		// 	map->grid = new_grid;
		// }
		// map->grid[map->height] = line;
		// map->height++;
	}
	close(fd);
	return map;
}

t_sprite	*ft_process_map(t_so_long *so_long, t_map *map)
{
	int			y;
	int			x;
	t_sprite	*img;

	if (!so_long || !map)
		return (ft_print_error("Faced ERROR when processing map!", NULL), NULL);
	img = (t_sprite *) malloc(1 * sizeof(t_sprite));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(so_long->mlx, map->width * 100, map->height * 100);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			switch (map->grid[y][x])
			{
			case '0':
				put_img_to_img(img, so_long->sprites[0], x * 100, y * 100);
				break;

			case '1':
				put_img_to_img(img, so_long->sprites[1], x * 100, y * 100);
				break;

			case 'C':
				put_img_to_img(img, so_long->sprites[2], x * 100, y * 100);
				break;

			case '3':
				put_img_to_img(img, so_long->sprites[3], x * 100, y * 100);
				break;

			case 'P':
				put_img_to_img(img, so_long->sprites[4], x * 100, y * 100);
				break;

			default:
				break;
			}
		}
	}
	return (img);
}
