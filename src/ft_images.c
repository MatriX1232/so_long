/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:53 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/02 13:43:46 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_img_info(t_sprite *img)
{
	if (img)
	{
		printf("Path: %s\n", img->path);
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
	if (!ret)
		return (ft_print_error("Cannot allocate memory for sprite: ", path), NULL);
	ret->img = mlx_xpm_file_to_image(mlx, path, &(ret->width), &(ret->height));
	ret->addr = mlx_get_data_addr(ret->img, &(ret->bits_per_pixel), &(ret->line_length), &(ret->endian));
	ret->path = path;
	return (ret);
}

t_sprite	**ft_load_sprites(void *mlx)
{
	t_sprite	**sprites;

	sprites = (t_sprite **) malloc(5 * sizeof(t_sprite *));
	if (!sprites)
		return (ft_print_error("Cannot allocate memory for sprites!", NULL), NULL);
	sprites[0] = NULL;
	sprites[1] = xpm_load_image(mlx, "textures/other_1.xpm");
	sprites[2] = xpm_load_image(mlx, "textures/coin_0.xpm");
	sprites[3] = xpm_load_image(mlx, "textures/gate.xpm");
	sprites[4] = xpm_load_image(mlx, "textures/cat_0.xpm");
	ft_cprint(GREEN, "All sprites loaded sucessfully!\n");
	return (sprites);
}
