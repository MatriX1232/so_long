/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:57:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/22 12:00:25 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_null(void *w)
{
	w = (void *) malloc(sizeof(NULL));
	w = NULL;
	return (w);
}

static void	ft_freeall(char **words, int wid)
{
	while (wid >= 0)
	{
		free(words[wid]);
		wid--;
	}
	free(words);
}

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i) == '\0')
			break ;
		count++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (count);
}

static char	*ft_fillword(char **words, int wid, char *s, char c)
{
	int	size;
	int	i;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	i = 0;
	words[wid] = (char *) malloc(sizeof(char) * (size + 1));
	if (!words[wid])
	{
		ft_freeall(words, wid);
		return (NULL);
	}
	while (s[i] && s[i] != c)
	{
		words[wid][i] = s[i];
		i++;
	}
	words[wid][i] = '\0';
	return (words[wid]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wid;
	char	**words;
	char	*ss;

	ss = (char *)s;
	words = (char **) malloc((sizeof(char *) * (ft_word_count(ss, c) + 1)) + 1);
	if (!words)
		return (NULL);
	i = 0;
	wid = 0;
	while (*(ss + i))
	{
		while (*(ss + i) && *(ss + i) == c)
			i++;
		if (*(ss + i) == '\0')
			break ;
		words[wid] = ft_fillword(words, wid, ss + i, c);
		wid++;
		while (*(ss + i) && *(ss + i) != c)
			i++;
	}
	words[wid] = ft_alloc_null(words[wid]);
	return (words);
}
