/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:12:24 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/09 17:06:48 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

#define BPX 100

typedef struct s_so_long
{
	void	*mlx;
	void	*mlx_win;
} t_so_long;


typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_sprite;

void			ft_print_img_info(t_sprite *img);
t_sprite		*xpm_load_image(void *mlx, char *path);
unsigned int	ft_get_pixel_value(t_sprite *img, int x, int y);
void			ft_put_alpha_image(t_so_long *so_long, t_sprite *img, int x, int y, unsigned int alpha_color);

#endif
