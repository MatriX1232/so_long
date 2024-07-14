/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:08:53 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/14 17:01:28 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_file.h"
#include "../so_long.h"
#include "../include/ft_window.h"
#include <fcntl.h>

void	ft_print_error(char *error, char *path)
{
	write(1, (char *)RED, ft_strlen(RED));
	write(1, error, ft_strlen(error));
	write(1, path, ft_strlen(path));
	write(1, (char *)END, ft_strlen(END));
	write(1, "\n", 1);
}

void	ft_debug_log(char *str)
{
	write(1, (char *)BOLD, ft_strlen(BOLD));
	ft_cprint(YELLOW, str);
}

int	ft_count_char(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_fopen(t_so_long *so_long, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error("ERROR when reading map: ", path);
		ft_exit(so_long, 0, 1, 0);
		return (1);
	}
	return (fd);
}
