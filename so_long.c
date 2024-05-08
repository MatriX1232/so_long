/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:55 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/07 20:13:40 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_free_all_tiles(void *mlx, t_sprite **tiles)
{
	int	i;

	i = 0;
	while (tiles[i] != NULL)
	{
		mlx_destroy_image(mlx, tiles[i]->img);
		free(tiles[i]);
		i++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_sprite *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_sprite	*xpm_load_image(void *mlx, char *path)
{
	static t_sprite	ret;
	int			width;
	int			height;

	// ret = (t_sprite *) malloc(1 * sizeof(t_sprite));
	// ret->img = NULL;
	// ret->addr = NULL;
	// ret->width = 0;
	// ret->heigth = 0;
	// ret->bits_per_pixel = 0;
	// ret->line_length = 0;
	// ret->endian = 0;
	width = 0;
	height = 0;
	// img = NULL;
	// path = ft_fix_path(path);
	ret.img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	ret.width = width;
	ret.heigth = height;
	// ret->addr = mlx_get_data_addr(&(ret->img), &(ret->bits_per_pixel), &(ret->line_length), &(ret->endian));
	printf("Path: %s | Img width: %d | Img heigth: %d\n", path, ret.width, ret.heigth);
	return (&ret);
}

int	main()
{
	void	*mlx;
	void	*mlx_win;

	int		map_width;
	int		map_heigth;
	int		map_width_tiles = 10;
	int		map_heigth_tiles = 6;

	// t_data	**tiles;
	t_sprite	*background;
	t_sprite	*player;

	mlx = mlx_init();

	background = xpm_load_image(mlx, "textures/other_0.xpm");
	player = xpm_load_image(mlx, "textures/cat_0.xpm");
	// background->width = 0;
	// background->heigth = 0;
	// background = mlx_xpm_file_to_image(mlx, "textures/other_0.xpm", &background->width, &background->heigth);

	map_width = background->width * map_width_tiles;
	map_heigth = background->heigth * map_heigth_tiles;

	// img = mlx_png_file_to_image(mlx, path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, map_width, map_heigth, "SO_LONG GAME");



	// image.img = img;
	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	for (int y=0; y < map_width_tiles; y++)
	{
		for (int x=0; x < map_width_tiles; x++)
		{
			mlx_put_image_to_window(mlx, mlx_win, background->img, x * (background->width), y * (background->heigth));
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, player->img, 0, 0);
	// img.img = mlx_new_image(mlx, 512, 512);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	printf("Hex color: %X | %X\n", 0xFFE5F9FF, create_trgb(255, 229, 249, 255));
	mlx_destroy_image(mlx, background->img);
	free(background);
	mlx_destroy_image(mlx, player->img);
	free(player);

	mlx_loop(mlx);

	return (0);
}
