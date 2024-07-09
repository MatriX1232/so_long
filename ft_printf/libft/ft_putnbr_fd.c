/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:43 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/05 20:46:02 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = n + '0';
		write(fd, &tmp, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
