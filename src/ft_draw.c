/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:03:20 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/20 15:24:50 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// unsigned int	ft_get_pixel_value(t_sprite *img, int x, int y)
// {
// 	return (*(unsigned int *)((img->addr
// 			+ (y * img->line_length) + (x * img->bits_per_pixel / 8))));
// }

// void put_pixel(t_sprite *sprite, int x, int y, Color color) {
//     int pixel = (y * sprite->line_length) + (x * (sprite->bits_per_pixel / 8));
//     int color_int = color_to_int(color);
//     *(int *)(sprite->addr + pixel) = color_int;
// }

// Color get_background_pixel(t_sprite *mlx_data, int x, int y)
// {
//     int pixel = (y * mlx_data->line_length) + (x * (mlx_data->bits_per_pixel / 8));
//     int color_int = *(int *)(mlx_data->addr + pixel);
//     return (int_to_color(color_int));
// }

// Color get_pixel(t_sprite *mlx_data, int x, int y) {
//     int pixel = (y * mlx_data->line_length) + (x * (mlx_data->bits_per_pixel / 8));
//     int color_int = *(int *)(mlx_data->addr + pixel);
//     return int_to_color(color_int);
// }

// void put_pixel_with_alpha(t_sprite *sprite, int x, int y, Color color) {
//     Color bg_color = get_pixel(sprite, x, y);
//     Color blended_color = blend(color, bg_color);
//     put_pixel(sprite, x, y, blended_color);
// }

// void	ft_put_alpha_image(t_so_long *so_long, t_sprite *img, int x, int y, unsigned int alpha_color)
// {
// 	int	xx;
// 	int	yy;

// 	// (void)x;
// 	// (void)y;
// 	// (void)so_long;
// 	yy = 0;
// 	while (yy < img->height)
// 	{
// 		xx = 0;
// 		while (xx < img->width)
// 		{
// 			if (alpha_color == ft_get_pixel_value(img, xx, yy))
// 				continue ;
// 			// printf("Pixel value: %u\n", ft_get_pixel_value(img, xx, yy));
// 			mlx_pixel_put(so_long->mlx, so_long->win, x + xx, y + yy, (int)ft_get_pixel_value(img, xx, yy));
// 			// printf("mlx_pixel_put\n");
// 			xx++;
// 		}
// 		yy++;
// 	}
// }

// char	*ft_convert_aplha(t_sprite *img, int desired_aplha)
// {
// 	// char	*data = mlx_get_data_addr(img->addr, img->bits_per_pixel, img->line_length, img->endian);
// 	char	*data = img->addr;
// 	for (int y = 0; y < img->height; y++)
// 	{
// 		for(int x = 0; x < img->width; x++)
// 		{
// 			int pixel = x + y * img->line_length / (img->bits_per_pixel / 8);
// 			data[pixel] = (data[pixel] & 0xFFFFFF00) | desired_aplha;
// 		}
// 	}
// 	return (data);
// }
