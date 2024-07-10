/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:23 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/10 09:57:33 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "include/ft_window.h"
#include "include/ft_game.h"
#include "include/get_next_line.h"

int	keyhook(int keycode, t_so_long *so_long)
{
	if (!so_long)
		return (0);
	printf("Key pressed: %c | %d\n", keycode, keycode);

	if (keycode == 'w')
		so_long->map = ft_map_update(so_long, so_long->map, 0, -1);
	if (keycode == 's')
		so_long->map = ft_map_update(so_long, so_long->map, 0, 1);
	if (keycode == 'a')
		so_long->map = ft_map_update(so_long, so_long->map, -1, 0);
	if (keycode == 'd')
		so_long->map = ft_map_update(so_long, so_long->map, 1, 0);
	return (0);
}

int	main()
{
	t_so_long	so_long;
	int			map_width;
	int			map_height;

	so_long.mlx = mlx_init();
	so_long.coins = 0;

	so_long.map = ft_load_map("maps/mini4.ber");
	so_long.backup_map = ft_copy_map(so_long.backup_map, so_long.map);

	ft_printf("<MAP> | Width: %d | Height: %d\n", so_long.map->width, so_long.map->height);
	map_width = so_long.map->width * 100;
	map_height = so_long.map->height * 100;
	ft_win_init(&so_long, map_width, map_height);
	ft_print_img_info(&so_long.main_img);
	so_long.sprites = ft_load_sprites(so_long.mlx);
	ft_process_map(&so_long, so_long.map);
	mlx_key_hook(so_long.win, keyhook, &so_long);
	mlx_hook(so_long.win, ON_DESTROY, 0, ft_exit, &so_long);

	mlx_loop(so_long.mlx);

	return (0);
}
