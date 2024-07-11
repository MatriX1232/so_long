/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:08:50 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/11 12:39:37 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_map.h"
#include "../so_long.h"

int	ft_ccoins(t_map *map)
{
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map->height)
	{
		count += ft_count_char('C', map->grid[y]);
		y++;
	}
	return (count);
}
