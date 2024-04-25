/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:14:06 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/12 19:41:36 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				ret;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	ret = 0;
	while ((*ss1 || *ss2) && n > 0)
	{
		if (*ss1 != *ss2)
		{
			ret = *ss1 - *ss2;
			break ;
		}
		n--;
		ss1++;
		ss2++;
	}
	return (ret);
}
