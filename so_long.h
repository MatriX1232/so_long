/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:12:24 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/20 15:54:12 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

// #include "mlx_transparent/include/libtransparency.h"

#define BPX 100

typedef struct {
    int r;
    int g;
    int b;
    int a;
} Color;

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

typedef struct {
    void		*mlx;
    void		*win;
    t_sprite	main_img;
} t_so_long;

void			ft_print_img_info(t_sprite *img);
t_sprite		*xpm_load_image(void *mlx, char *path);
// unsigned int	ft_get_pixel_value(t_sprite *img, int x, int y);
// void			ft_put_alpha_image(t_so_long *so_long, t_sprite *img, int x, int y, unsigned int alpha_color);
// char			*ft_convert_aplha(t_sprite *img, int desired_aplha);
Color			blend(Color src, Color dst);
// Color			ft_get_background_pixel(unsigned int color);
Color			int_to_color(int color);
// Color			get_pixel(t_sprite *mlx_data, int x, int y);
int				color_to_int(Color color);
// void 			put_pixel_with_alpha(t_sprite *sprite, int x, int y, Color color);
// void 			put_pixel(t_sprite *mlx_data, int x, int y, Color color);
// void			put_image_with_alpha(t_sprite *main_img, t_sprite *src, int x_offset, int y_offset);

#endif
