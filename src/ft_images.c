/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:53 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/21 12:56:22 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_img_info(t_sprite *img)
{
	if (img)
	{
		printf("Path: %s\n", img->addr);
		printf("Bits_per_pixel: %d\n", img->bits_per_pixel);
		printf("Line_length: %d\n", img->line_length);
		printf("Width | Height: %d x %d\n", img->width, img->height);
		printf("Endian: %d\n\n", img->endian);
	}
}

t_sprite	*xpm_load_image(void *mlx, char *path)
{
	t_sprite	*ret;

	ret = (t_sprite *) malloc(1 * sizeof(t_sprite));
	ret->img = mlx_xpm_file_to_image(mlx, path, &(ret->width), &(ret->height));
	ret->addr = mlx_get_data_addr(ret->img, &(ret->bits_per_pixel), &(ret->line_length), &(ret->endian));
	return (ret);
}
