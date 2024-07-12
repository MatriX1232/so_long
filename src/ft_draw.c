/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:03:20 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/12 18:03:08 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../include/ft_utils.h"

unsigned int	get_pixel_img(t_sprite *img, int x, int y)
{
	return (*(unsigned int *)((img->addr
			+ (y * img->line_length) + (x * img->bits_per_pixel / 8))));
}

void	put_pixel_img(t_sprite *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_length + \
				x * (img->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	put_img_to_img(t_sprite *dst, t_sprite *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	ft_print_ui(t_so_long *so_long)
{
	char	*str;
	char	*coins;
	char	*all_coins;
	char	*moves;

	coins = ft_itoa(so_long->coins);
	coins = ft_strjoin_free("COINS: ", coins, 0, 1);
	all_coins = ft_itoa(so_long->map->coins);
	all_coins = ft_strjoin_free(" / ", all_coins, 0, 1);
	str = ft_strjoin_free(coins, all_coins, 1, 1);
	mlx_string_put(so_long->mlx, so_long->win, 10, 30, 0x00FF00, str);
	free(str);
	moves = ft_itoa(so_long->moves);
	str = ft_strjoin_free("MOVES: ", moves, 0, 1);
	mlx_string_put(so_long->mlx, so_long->win, 10, 50, 0x00FF00, str);
	free(str);
	ft_printf("%sNumber of moves: %d%s\n", YELLOW, so_long->moves, END);
}

void	ft_print_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		ft_printf("%s\n", map->grid[y]);
		y++;
	}
}
