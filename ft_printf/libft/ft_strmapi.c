/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:11:56 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/22 13:04:38 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new;

	if (!s)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		new[i] = (*f)((unsigned int)i, (char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
