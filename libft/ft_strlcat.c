/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:14:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/22 13:10:21 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	j;

	if (!dest && size == 0)
		return (ft_strlen(src) + size);
	dlen = 0;
	j = 0;
	while (*(dest + dlen) && dlen < size)
		dlen++;
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + j) && dlen + j < size - 1)
	{
		*(dest + dlen + j) = *(src + j);
		j++;
	}
	if (dlen < size)
		*(dest + dlen + j) = '\0';
	return (ft_strlen(src) + dlen);
}
