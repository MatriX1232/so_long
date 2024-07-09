/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:14:05 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/19 14:40:43 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_at(const char *nptr, int i, int flag)
{
	int	n;

	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		n = n * 10;
		n = n + (nptr[i] - '0');
		i++;
	}
	if (flag)
		n *= (-1);
	return (n);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = 1;
		i++;
	}
	return (ft_at(nptr, i, flag));
}
