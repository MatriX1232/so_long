/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:22:17 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/21 15:15:14 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	color_to_int(t_Color color)
{
	return ((color.a << 24) | (color.r << 16) | (color.g << 8) | color.b);
}

t_Color	int_to_color(int color)
{
	t_Color	c;

	c.a = (color >> 24) & 0xFF;
	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = color & 0xFF;
	return (c);
}

t_Color	blend(t_Color src, t_Color dst)
{
	t_Color	result;
	float	alpha;

	alpha = src.a / 255.0;
	result.r = (int)(src.r * alpha + dst.r * (1 - alpha));
	result.g = (int)(src.g * alpha + dst.g * (1 - alpha));
	result.b = (int)(src.b * alpha + dst.b * (1 - alpha));
	result.a = 255;
	return (result);
}
