/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:55 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/25 17:10:28 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	image;
	void	*img;
	char	*path = "42warsaw.png";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "SO_LONG GAME");

	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);

	image.img = img;
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);

	// img.img = mlx_new_image(mlx, 512, 512);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	mlx_loop(mlx);

	return (0);
}
