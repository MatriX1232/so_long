/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:23 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/21 12:56:59 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_so_long *so_long)
{
	if (!so_long)
		return (0);
	printf("Key pressed: %c | %d\n", keycode, keycode);
	return (0);
}

int	main()
{
	t_so_long	so_long;
	int			map_width;
	int			map_height;
	int			map_width_tiles = 10 / 2;
	int			map_height_tiles = 6 / 2;
	t_sprite	*background;
	t_sprite	*player;

	so_long.mlx = mlx_init();

	background = xpm_load_image(so_long.mlx, "textures/dirt_0.xpm");
	player = xpm_load_image(so_long.mlx, "textures/cat_0.xpm");

	map_width = background->width * map_width_tiles;
	map_height = background->height * map_height_tiles;

	so_long.win = mlx_new_window(so_long.mlx, map_width, map_height, "SO_LONG GAME");
	so_long.main_img.img = mlx_new_image(so_long.mlx, map_width, map_height);
	so_long.main_img.addr = mlx_get_data_addr(so_long.main_img.img, &so_long.main_img.bits_per_pixel, &so_long.main_img.line_length, &so_long.main_img.endian);
	so_long.main_img.width = map_width;
	so_long.main_img.height = map_height;

	ft_print_img_info(&so_long.main_img);
	ft_print_img_info(background);
	ft_print_img_info(player);

	for (int y=0; y < map_width_tiles; y++)
	{
		for (int x=0; x < map_width_tiles; x++)
		{
			put_img_to_img(&so_long.main_img, background, x * (background->width), y * (background->height));
		}
	}

	put_img_to_img(&so_long.main_img, player, 0, 0);

	mlx_put_image_to_window(so_long.mlx, so_long.win, so_long.main_img.img, 0, 0);

	mlx_destroy_image(so_long.mlx, background->img);
	free(background);
	mlx_destroy_image(so_long.mlx, player->img);
	free(player);

	mlx_key_hook(so_long.win, keyhook, &so_long);
	mlx_loop(so_long.mlx);
	mlx_destroy_window(so_long.mlx, so_long.win);

	return (0);
}
