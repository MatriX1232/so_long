/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:23 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/02 18:00:21 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "include/ft_window.h"
#include "include/get_next_line.h"

int	keyhook(int keycode, t_so_long *so_long)
{
	if (!so_long)
		return (0);
	printf("Key pressed: %c | %d\n", keycode, keycode);

	if (keycode == 'w')
		so_long->map = ft_map_update(so_long, so_long->map, 0, -1);
	if (keycode == 's')
		so_long->map = ft_map_update(so_long, so_long->map, 0, 1);
	if (keycode == 'a')
		so_long->map = ft_map_update(so_long, so_long->map, -1, 0);
	if (keycode == 'd')
		so_long->map = ft_map_update(so_long, so_long->map, 1, 0);
	return (0);
}

int	main()
{
	t_so_long	so_long;
	int			map_width;
	int			map_height;
	// int			map_width_tiles = 10 / 2;
	// int			map_height_tiles = 6 / 2;
	// t_sprite	*background;
	// t_sprite	*player;
	t_sprite	*mainBG;

	so_long.mlx = mlx_init();

	// background = xpm_load_image(so_long.mlx, "textures/gate.xpm");
	// player = xpm_load_image(so_long.mlx, "textures/cat_0.xpm");

	so_long.map = ft_load_map("maps/mini4.ber");
	// so_long.backup_map = ft_load_map("maps/1.ber");
	printf("<MAP> | Width: %d | Height: %d\n", so_long.map->width, so_long.map->height);
	map_width = so_long.map->width * 100;
	map_height = so_long.map->height * 100;


	so_long.win = mlx_new_window(so_long.mlx, map_width, map_height, "SO_LONG GAME");
	so_long.main_img.img = mlx_new_image(so_long.mlx, map_width, map_height);
	so_long.main_img.addr = mlx_get_data_addr(so_long.main_img.img, &so_long.main_img.bits_per_pixel, &so_long.main_img.line_length, &so_long.main_img.endian);
	so_long.main_img.width = map_width;
	so_long.main_img.height = map_height;

	so_long.win_width = map_width;
	so_long.win_height = map_height;

	ft_print_img_info(&so_long.main_img);
	// ft_print_img_info(background);
	// ft_print_img_info(player);


	so_long.sprites = ft_load_sprites(so_long.mlx);

	mainBG = ft_process_map(&so_long, so_long.map);
	// if (!mainBG) write(1, "", 1);
	put_img_to_img(&so_long.main_img, mainBG, 0, 0);
	// mlx_put_image_to_window(so_long.mlx, so_long.win, mainBG, 0, 0);

	// for (int y=0; y < 3; y++)
	// {
	// 	for (int x=0; x < 6; x++)
	// 	{
	// 		put_img_to_img(&so_long.main_img, so_long.sprites[1], x * (so_long.sprites[1]->width), y * (so_long.sprites[1]->height));
	// 	}
	// }

	// put_img_to_img(&so_long.main_img, so_long.sprites[4], 0, 0);

	// mlx_put_image_to_window(so_long.mlx, so_long.win, so_long.main_img.img, 0, 0);

	mlx_key_hook(so_long.win, keyhook, &so_long);
	mlx_hook(so_long.win, ON_DESTROY, 0, ft_EXIT, &so_long);
	// mlx_hook(so_long.win, 9, 1L << 4, ft_RESIZE, &so_long);

	mlx_loop(so_long.mlx);

	return (0);
}
