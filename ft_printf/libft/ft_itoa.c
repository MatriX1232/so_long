/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/19 15:00:30 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa_internal(char *num, int n, int i, int minus)
{
	while (n > 0)
	{
		if (minus && i == 0)
			break ;
		*(num + i--) = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}

static char	*ft_min_zero(void)
{
	char	*num;

	num = (char *) malloc(sizeof(char) * 2);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char	*ft_min_int(void)
{
	char	*num;

	num = (char *) malloc(sizeof(char) * 12);
	if (!num)
		return (NULL);
	ft_strlcpy(num, "-2147483648", 12);
	return (num);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		i;
	char	*num;

	minus = 0;
	if (n == 0)
		return (ft_min_zero());
	if (n == -2147483648)
		return (ft_min_int());
	if (n < 0)
		minus = 1;
	num = (char *) malloc(sizeof(char) * (ft_intlen(n) + minus + 1));
	if (!num)
		return (NULL);
	i = ft_intlen(n);
	if (minus)
	{
		n *= (-1);
		*num = '-';
		i = ft_intlen(n) + 1;
	}
	*(num + i--) = '\0';
	return (num = ft_itoa_internal(num, n, i, minus));
}
