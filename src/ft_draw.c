/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:03:20 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/09 17:12:10 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned int	ft_get_pixel_value(t_sprite *img, int x, int y)
{
	return (*(unsigned int *)((img->addr
			+ (y * img->line_length) + (x * img->bits_per_pixel / 8))));
}

void	ft_put_alpha_image(t_so_long *so_long, t_sprite *img, int x, int y, unsigned int alpha_color)
{
	int	xx;
	int	yy;

	// (void)x;
	// (void)y;
	// (void)so_long;
	yy = 0;
	while (yy < img->height)
	{
		xx = 0;
		while (xx < img->width)
		{
			if (alpha_color == ft_get_pixel_value(img, xx, yy))
				continue ;
			// printf("Pixel value: %u\n", ft_get_pixel_value(img, xx, yy));
			mlx_pixel_put(so_long->mlx, so_long->mlx_win, x + xx, y + yy, (int)ft_get_pixel_value(img, xx, yy));
			// printf("mlx_pixel_put\n");
			xx++;
		}
		yy++;
	}
}
