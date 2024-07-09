/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:22 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/09 17:19:35 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "ft_structures.h"

t_map		*ft_load_map(char *path);
void		ft_print_error(char *error, char *path);
void		ft_process_map(t_so_long *so_long, t_map *map);
void		ft_map_switch(t_so_long *so_long, t_map *map, int x, int y);
t_map		*ft_map_update(t_so_long *so_long, t_map *map, int x, int y);
t_map		*ft_copy_map(t_map *dest, t_map *src);

#endif
