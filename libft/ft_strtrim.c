/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/22 13:12:09 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Why to rewrite everything when we could use previous funcions :)	*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_size;
	char	*s;
	char	*sset;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	sset = (char *)set;
	while (ft_strchr(sset, *s) && *s)
		s++;
	new_size = ft_strlen((const char *)s);
	while (ft_strchr(sset, s[new_size]) && new_size)
		new_size--;
	return (ft_substr(s, 0, new_size + 1));
}
