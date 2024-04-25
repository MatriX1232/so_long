/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:14:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/12 19:19:50 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (*s == '\0' && c == '\0')
	{
		return ((char *)s);
	}
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (*(s + i) == c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
