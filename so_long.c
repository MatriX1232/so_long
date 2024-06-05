/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:55 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/05 11:44:23 by msolinsk         ###   ########.fr       */
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


int	main()
{
	t_so_long	so_long;
	// void	*mlx;
	// void	*mlx_win;

	int			map_width;
	int			map_height;
	int			map_width_tiles = 10;
	int			map_heigth_tiles = 6;

	// t_data	**tiles;
	t_sprite	*background;
	t_sprite	*player;

	so_long.mlx = mlx_init();

	background = xpm_load_image(so_long.mlx, "textures/other_0.xpm");
	player = xpm_load_image(so_long.mlx, "textures/cat_0.xpm");

	ft_print_img_info(background);
	ft_print_img_info(player);

	// background->width = 0;
	// background->heigth = 0;
	// background = mlx_xpm_file_to_image(mlx, "textures/other_0.xpm", &background->width, &background->heigth);

	map_width = background->width * map_width_tiles;
	map_height = background->height * map_heigth_tiles;

	// img = mlx_png_file_to_image(mlx, path, &img_width, &img_height);
	so_long.mlx_win = mlx_new_window(so_long.mlx, map_width, map_height, "SO_LONG GAME");



	// image.img = img;
	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	for (int y=0; y < map_width_tiles; y++)
	{
		for (int x=0; x < map_width_tiles; x++)
		{
			mlx_put_image_to_window(so_long.mlx, so_long.mlx_win, background->img, x * (background->width), y * (background->height));
		}
	}
	// mlx_put_image_to_window(so_long.mlx, so_long.mlx_win, player->img, 0, 0);
	ft_put_alpha_image(&so_long, player, 0, 0, 0xFF000000);

	// img.img = mlx_new_image(mlx, 512, 512);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	printf("Hex color: %X | %X\n", 0xFFE5F9FF, create_trgb(255, 229, 249, 255));

	mlx_destroy_image(so_long.mlx, background->img);
	free(background);
	mlx_destroy_image(so_long.mlx, player->img);
	free(player);

	mlx_loop(so_long.mlx);
	mlx_destroy_window(so_long.mlx, so_long.mlx_win);

	return (0);
}
