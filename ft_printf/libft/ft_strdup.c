/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/22 13:10:01 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			i;
	char		*d;
	const char	*ss;

	ss = s;
	d = (char *) malloc((sizeof(char) * ft_strlen(ss)) + 1);
	if (!d)
		return (NULL);
	if (*s == '\0')
		*d = '\0';
	i = 0;
	while (*(ss + i))
	{
		*(d + i) = *(ss + i);
		i++;
	}
	d[i] = '\0';
	return (d);
}
