/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:08:22 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 20:39:53 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "ft_structures.h"
# include <stdbool.h>

t_map		*ft_load_map(t_so_long *so_long, char *path);
void		ft_print_error(char *error, char *path);
void		ft_process_map(t_so_long *so_long, t_map *map);
void		ft_map_switch(t_so_long *so_long, t_map *map, int x, int y);
t_map		*ft_map_update(t_so_long *so_long, t_map *map, int x, int y);
t_map		*ft_copy_map(t_map *dest, t_map *src);
t_map		*ft_malloc_map(t_map *map, int height);
int			ft_check_map(t_map *map);
int			ft_ccoins(t_map *map);
int			ft_check_if_move(t_so_long *so_long, t_map *map, t_point p);
void		ft_floodfill(t_map *map, t_point p, char c_exit, bool *exit);
t_point		ft_get_start_point(t_map *map);
bool		ft_map_swich_main(t_so_long *so_long, t_map *map, int x, int y);
t_map		*ft_load_init(t_so_long *so_long, char *path, int *fd);
int			ft_get_map_height(int fd);
bool		ft_cipem(t_so_long *so_long, t_point p);

#endif
