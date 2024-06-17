/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:22:17 by msolinsk          #+#    #+#             */
/*   Updated: 2024/06/17 13:20:06 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int color_to_int(Color color)
{
    return ((color.a << 24) | (color.r << 16) | (color.g << 8) | color.b);
}

Color int_to_color(int color)
{
    Color c;
    c.a = (color >> 24) & 0xFF;
    c.r = (color >> 16) & 0xFF;
    c.g = (color >> 8) & 0xFF;
    c.b = color & 0xFF;
    return c;
}

Color blend(Color src, Color dst) {
    Color result;
    float alpha = src.a / 255.0;
    result.r = (int)(src.r * alpha + dst.r * (1 - alpha));
    result.g = (int)(src.g * alpha + dst.g * (1 - alpha));
    result.b = (int)(src.b * alpha + dst.b * (1 - alpha));
    result.a = 255;
    return result;
}
