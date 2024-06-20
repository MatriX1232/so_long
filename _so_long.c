/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:55 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/20 15:54:38 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

	// char *data = ft_convert_aplha(player, 0xFFFFFF00);
	// player->addr = data;

	// background->width = 0;
	// background->heigth = 0;
	// background = mlx_xpm_file_to_image(mlx, "textures/other_0.xpm", &background->width, &background->heigth);

	map_width = background->width * map_width_tiles;
	map_height = background->height * map_heigth_tiles;

	// img = mlx_png_file_to_image(mlx, path, &img_width, &img_height);
	so_long.win = mlx_new_window(so_long.mlx, map_width, map_height, "SO_LONG GAME");
	so_long.main_img = mlx_new_image(so_long.mlx, map_width, map_height);
	so_long.main_img->addr = mlx_get_data_addr(so_long.mlx, &so_long.main_img.bits_per_pixel, &so_long.main_img.line_length, &so_long.main_img.endian);
	so_long.main_img->width = map_width;
	so_long.main_img->height = map_height;

	// Color bg_color = {0, 0, 255, 255}; // Blue color
    // for (int y = 0; y < map_height; y++) {
    //     for (int x = 0; x < map_width; x++) {
    //         put_pixel(so_long.main_img, x, y, bg_color);
    //     }
    // }

	// Fill the sprite image with semi-transparent red
    Color semi_transparent_red = {255, 0, 0, 128}; // 50% transparent red
    for (int y = 0; y < background->height; y++) {
        for (int x = 0; x < background->width; x++) {
            put_pixel(background, x, y, semi_transparent_red);
        }
    }

	put_image_with_alpha(so_long.main_img, background, 300, 200);
	mlx_put_image_to_window(so_long.mlx, so_long.win, so_long.main_img->img, 0, 0);

	// image.img = img;
	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	// for (int y=0; y < map_width_tiles; y++)
	// {
	// 	for (int x=0; x < map_width_tiles; x++)
	// 	{
	// 		mlx_put_image_to_window(so_long.mlx, so_long.win, background->img, x * (background->width), y * (background->height));
	// 	}
	// }

	// mlx_put_image_to_window(so_long.mlx, so_long.mlx_win, player->img, 0, 0);
	// ft_put_alpha_image(&so_long, player, 0, 0, 0xFF000000);

	// img.img = mlx_new_image(mlx, 512, 512);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// t_color transparent = {255, 0, 0, 0};
	// transparent.a = None;
	// transparent.r = 0;
	// transparent.g = 0;
	// transparent.b = 0;
	// put_pixel_with_alpha(so_long.mlx, so_long.mlx_win, player, 100 ,100, transparent);

	// Color	bg_color = {0, 0, 255, 255}; // Blue color
    // for (int y = 0; y < map_height; y++) {
    //     for (int x = 0; x < map_width; x++) {
    //         put_pixel(&so_long, x, y, bg_color);
    //     }
    // }

	// printf("Hex color: %X | %X\n", 0xFFE5F9FF, create_trgb(255, 229, 249, 255));

	printf("Unsigned int value: %u\n", ft_get_pixel_value(background, 0, 0));

	mlx_destroy_image(so_long.mlx, background->img);
	free(background);
	mlx_destroy_image(so_long.mlx, player->img);
	free(player);

	mlx_loop(so_long.mlx);
	mlx_destroy_window(so_long.mlx, so_long.win);

	return (0);
}


// int main() {
//     MLXData mlx_data;
//     int width = 800;
//     int height = 600;

//     mlx_data.mlx = mlx_init();
//     mlx_data.win = mlx_new_window(mlx_data.mlx, width, height, "MLX Window");
//     mlx_data.img = mlx_new_image(mlx_data.mlx, width, height);
//     mlx_data.data = mlx_get_data_addr(mlx_data.img, &mlx_data.bpp, &mlx_data.size_line, &mlx_data.endian);

//     // Fill the background with a color (e.g., blue)
//     Color bg_color = {0, 0, 255, 255}; // Blue color
//     for (int y = 0; y < height; y++) {
//         for (int x = 0; x < width; x++) {
//             put_pixel(&mlx_data, x, y, bg_color);
//         }
//     }

//     // Put a semi-transparent red pixel at the center
//     Color semi_transparent_red = {255, 0, 128, 128}; // 50% transparent red
//     put_pixel_with_alpha(&mlx_data, width / 2, height / 2, semi_transparent_red);

//     // Display the image in the window
//     mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img, 0, 0);
//     mlx_loop(mlx_data.mlx);

//     return 0;
// }
