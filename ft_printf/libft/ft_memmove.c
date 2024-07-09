/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:14:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/12 18:22:02 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;

	d = dest;
	if ((!dest && !src) || dest == src)
		return (dest);
	if (dest > src)
	{
		while (n-- > 0)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
	{
		while (n-- > 0)
			*(char *)dest++ = *(char *)src++;
	}
	return (d);
}
