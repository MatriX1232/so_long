/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:22 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/21 15:56:36 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

enum e_blocks
{
	EMPTY,
	WALL,
	COLLECTABLE,
	EXIT,
	PLAYER,
	ENEMY
};

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

t_map	*ft_load_map(char *path);
void	ft_print_error(char *error, char *path);

#endif
