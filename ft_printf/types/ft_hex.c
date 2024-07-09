/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:42:33 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/11 15:52:17 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hex_len(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned long long n, char form)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, form);
		ft_puthex(n % 16, form);
	}
	else
	{
		if (form == 'X')
			write(1, &"0123456789ABCDEF"[n % 16], 1);
		else if (form == 'x')
			write(1, &"0123456789abcdef"[n % 16], 1);
	}
}

int	ft_hex(unsigned long long n, char form, int prefix)
{
	int	total_len;

	total_len = ft_hex_len(n);
	if (prefix)
	{
		write(1, "0x", 2);
		total_len += 2;
	}
	ft_puthex(n, form);
	return (total_len);
}
