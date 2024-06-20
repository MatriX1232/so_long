/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:23 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/20 16:46:23 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libtransparency.h"
#include "so_long.h"

unsigned int	get_pixel_img(t_sprite *img, int x, int y) {
	return (*(unsigned int *)((img->addr
			+ (y * img->line_length) + (x * img->bits_per_pixel / 8))));
}

void	put_pixel_img(t_sprite *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height) {
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}


void	put_img_to_img(t_sprite *dst, t_sprite *src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src->width) {
		j = 0;
		while (j < src->height) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

int	main()
{
	t_so_long	so_long;
	int			map_width;
	int			map_height;
	int			map_width_tiles = 10;
	int			map_height_tiles = 6;
	t_sprite	*background;
	t_sprite	*player;

	so_long.mlx = mlx_init();

	background = xpm_load_image(so_long.mlx, "textures/other_0.xpm");
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

	put_img_to_img(&so_long.main_img, background, 0, 0);
	put_img_to_img(&so_long.main_img, player, 0, 0);

	// printf("Unsigned int value: %u\n", ft_get_pixel_value(background, 0, 0));

	mlx_put_image_to_window(so_long.mlx, so_long.win, so_long.main_img.img, 0, 0);

	mlx_destroy_image(so_long.mlx, background->img);
	free(background);
	mlx_destroy_image(so_long.mlx, player->img);
	free(player);

	mlx_loop(so_long.mlx);
	mlx_destroy_window(so_long.mlx, so_long.win);

	return 0;
}
