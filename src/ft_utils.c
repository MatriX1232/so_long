/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:50:20 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/12 14:52:59 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_utils.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	ft_ffree(char *s1, char *s2, int f1, int f2)
{
	if (f1)
		free(s1);
	if (f2)
		free(s2);
}

char	*ft_strjoin_free(char *s1, char *s2, int f1, int f2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	*(new + i + j) = '\0';
	ft_ffree(s1, s2, f1, f2);
	return (new);
}
