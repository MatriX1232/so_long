/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:45 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/06 13:30:33 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if ((int)(nmemb * size) > 2147483647 || (int)(nmemb * size) < -2147483648)
		return (NULL);
	array = (void *) malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}
