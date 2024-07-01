/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:05:40 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/01 16:01:12 by msolinsk         ###   ########.fr       */
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

t_map	*ft_load_map(char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

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
	close(fd);
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->grid[map->height] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		// printf("%s", map->grid[map->height]);
		map->height++;
	}
	close(fd);
	ft_cprint(GREEN, "Map loaded successfully!\n");
	return (map);
}

t_sprite	*ft_process_map(t_so_long *so_long, t_map *map)
{
	int			y;
	int			x;
	t_sprite	*img;

	if (!so_long || !map || !map->grid)
		return (ft_print_error("Faced ERROR when processing map!", NULL), NULL);
	img = (t_sprite *) malloc(1 * sizeof(t_sprite));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(so_long->mlx, so_long->win_width, so_long->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->width = map->width * 100;
	img->height = map->height * 100;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '\0')
				break ;
			switch (map->grid[y][x])
			{
				case '0':
					// put_img_to_img(img, so_long->sprites[0], x * 100, y * 100);
					break ;

				case '1':
					put_img_to_img(img, so_long->sprites[1], x * 100, y * 100);
					// mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->sprites[1]->img, x * 100, y * 100);
					break ;

				case 'C':
					put_img_to_img(img, so_long->sprites[2], x * 100, y * 100);
					// mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->sprites[2]->img, x * 100, y * 100);
					break ;

				case 'E':
					put_img_to_img(img, so_long->sprites[3], x * 100, y * 100);
					// mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->sprites[3]->img, x * 100, y * 100);
					break ;

				case 'P':
					put_img_to_img(img, so_long->sprites[4], x * 100, y * 100);
					// mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->sprites[4]->img, x * 100, y * 100);
					break ;

				default:
					ft_cprint(RED, "Encountered not supportted character | ");
					printf("%c | %d\n", map->grid[y][x], map->grid[y][x]);
					// write(1, &map->grid[y][x], 1);
					// write(1, "\n", 1);
					break;
			}
			x++;
		}
		y++;
	}
	ft_cprint(GREEN, "Map sprite generated successfully!\n");
	return (img);
}
