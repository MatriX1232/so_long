/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:53 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/07 18:42:21 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// char	*ft_fix_path(char *path)
// {
// 	char	*new;

// 	new = ft_strjoin("../../", path);
// 	return (new);
// }

// void	xpm_load_image(t_sprite *ret, void *mlx, char *path)
// {
// 	int	wd;

// 	wd = BPX;
// 	path = ft_fix_path(path);
// 	ret->img = mlx_xpm_file_to_image(mlx, path, &wd, &wd);
// 	printf("Path: %s | Img width: %d | Img heigth: %d\n", path, wd, wd);

// 	// return (ret);
// }

// t_sprite	*xpm_load_image(void *mlx, char *path)
// {
// 	t_sprite	*ret;
// 	void		*img;
// 	int			width;
// 	int			height;

// 	ret = (t_sprite *) malloc(1 * sizeof(t_sprite));
// 	// ret->img = NULL;
// 	// ret->addr = NULL;
// 	// ret->width = 0;
// 	// ret->heigth = 0;
// 	// ret->bits_per_pixel = 0;
// 	// ret->line_length = 0;
// 	// ret->endian = 0;
// 	width = 0;
// 	height = 0;
// 	img = NULL;
// 	path = ft_fix_path(path);
// 	img = mlx_xpm_file_to_image(mlx, path, &(ret->width), &height);
// 	ret->width = width;
// 	ret->heigth = height;
// 	ret->img = img;
// 	// ret->addr = mlx_get_data_addr(&(ret->img), &(ret->bits_per_pixel), &(ret->line_length), &(ret->endian));
// 	printf("Path: %s | Img width: %d | Img heigth: %d\n", path, ret->width, ret->heigth);
// 	return (ret);
// }
