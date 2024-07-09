/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:30:29 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/09 14:29:24 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_nbr(int n, int *len)
{
	char	tmp;

	if (n == -2147483648)
	{
		*len += (int)write(1, "-2", 2);
		n = 147483648;
	}
	else if (n < 0)
	{
		*len += write(1, "-", 1);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = n + '0';
		*len += write(1, &tmp, 1);
	}
	else if (n > 9)
	{
		ft_nbr(n / 10, len);
		ft_nbr(n % 10, len);
	}
}
