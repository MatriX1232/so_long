/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:09:22 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/10 14:06:02 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include "ft_structures.h"

void	ft_print_error(char *error, char *path);
void	ft_debug_log(char *str);
int		ft_fopen(t_so_long *so_long, char *path);

#endif
