/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:43:54 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/12 18:34:40 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_structures.h"

void	ft_win_init(t_so_long *so_long, int width, int height);
void	ft_parse_args(t_so_long *so_long, int argc);

#endif
