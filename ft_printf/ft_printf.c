/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:59 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/09 10:29:35 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_in_tab(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_arg_count(char *str)
{
	int		count;
	char	*set;

	count = 0;
	set = (char *) malloc(sizeof(char) * 11);
	if (!set)
		return (0);
	*set = '\0';
	ft_strlcat(set, "cspdiuxX%%", 11);
	while (*str)
	{
		if (*str == '%' && ft_check_in_tab(set, *(str + 1)))
			count++;
		if (*str == '%' && *(str + 1) == '%')
			str++;
		str++;
	}
	free(set);
	return (count);
}

int	ft_match(char c, va_list *arg, int *len)
{
	if (c == 'c')
		*len += ft_char(va_arg(*arg, int));
	else if (c == 's')
		*len += ft_str(va_arg(*arg, char *));
	else if (c == 'p')
		*len += ft_ptr(va_arg(*arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		ft_nbr(va_arg(*arg, int), len);
	else if (c == 'u')
		ft_uint(va_arg(*arg, unsigned int), len);
	else if (c == 'X')
		*len += ft_hex(va_arg(*arg, unsigned int), 'X', 0);
	else if (c == 'x')
		*len += ft_hex(va_arg(*arg, unsigned int), 'x', 0);
	else if (c == '%')
		*len += ft_char('%');
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		total_len;
	char	*tmp;
	va_list	list;

	va_start(list, str);
	total_len = 0;
	while (*str)
	{
		if (ft_get_arg_count((char *)str))
		{
			tmp = ft_strchr(str, '%');
			write(1, str, tmp - str);
			total_len += tmp - str;
			ft_match(tmp[1], &list, &total_len);
			str = tmp + 2;
		}
		else
		{
			write(1, str, ft_strlen(str));
			total_len += ft_strlen(str);
			break ;
		}
	}
	va_end(list);
	return (total_len);
}
