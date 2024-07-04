/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:53 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/04 12:15:12 by msolinsk         ###   ########.fr       */
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
	int			bpp;
	int			ll;
	int			ed;

	ret = (t_sprite *) malloc(1 * sizeof(t_sprite));
	if (!ret)
	{
		ft_print_error("Cannot allocate memory for sprite: ", path);
		return (NULL);
	}
	bpp = 0;
	ll = 0;
	ed = 0;
	ret->img = mlx_xpm_file_to_image(mlx, path, &(ret->width), &(ret->height));
	ret->addr = mlx_get_data_addr(ret->img, &bpp, &ll, &ed);
	ret->path = path;
	ret->bits_per_pixel = bpp;
	ret->line_length = ll;
	ret->endian = ed;
	return (ret);
}

t_sprite	**ft_load_sprites(void *mlx)
{
	t_sprite	**sprites;

	sprites = (t_sprite **) malloc(5 * sizeof(t_sprite *));
	if (!sprites)
	{
		ft_print_error("Cannot allocate memory for sprites!", NULL);
		return (NULL);
	}
	sprites[0] = xpm_load_image(mlx, "textures/other_0.xpm");
	sprites[1] = xpm_load_image(mlx, "textures/other_1.xpm");
	sprites[2] = xpm_load_image(mlx, "textures/coin_0.xpm");
	sprites[3] = xpm_load_image(mlx, "textures/gate.xpm");
	sprites[4] = xpm_load_image(mlx, "textures/cat_0.xpm");
	ft_cprint(GREEN, "All sprites loaded sucessfully!\n");
	return (sprites);
}
