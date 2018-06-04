/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:31:30 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 18:20:24 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		color_increment(int color, int num)
{
	if (color % 0x000100 == 0xFF && color >> 8 < 0xFF)
		color += 0x000100;
	else if (color > 0xFF && color < 0x010000 && color % 0x000100 > 0)
		color -= 0x000001;
	else if ((color & 0xFF00) == 0xFF00 && color >> 16 < 0xFF)
		color += 0x010000;
	else if (color >> 16 == 0xFF && color >> 8 > 0xFF00)
		color -= 0x000100;
	else if (color >> 16 == 0xFF && color % 0x000100 < 0xFF)
		color += 0x000001;
	else
		color -= 0x010000;
	if (num <= 1)
		return (color);
	return (color_increment(color, num - 1));
}

int		get_color(int i, int iter)
{
	int	color;

	if (i < iter / 2)
		color = (0xFF * (i + 1) / (iter / 2)) << 16;
	else
	{
		color = (0xFF * (i + 1 - (iter / 2)) / (iter / 2)) << 8;
		color += (0xFF * (i + 1 - (iter / 2)) / (iter / 2));
		color += 0xFF0000;
	}
	return (color);
}

int		rainbow(int i, t_img *img)
{
	return (color_increment(img->color, i * 10));
}

