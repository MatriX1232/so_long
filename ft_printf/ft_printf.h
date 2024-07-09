/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:59:28 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/11 15:48:13 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_char(char c);
int		ft_str(char *str);
int		ft_pointer(unsigned long long p);
int		ft_hex(unsigned long long n, char form, int prefix);
int		ft_ptr(unsigned long long ptr);
void	ft_nbr(int n, int *len);
void	ft_uint(unsigned int n, int *len);

#endif
