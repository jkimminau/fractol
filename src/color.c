/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:31:30 by jkimmina          #+#    #+#             */
/*   Updated: 2018/08/17 14:00:02 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		color_select(int color, int num)
{
	color += num;
	color %= 1536;
	if (color >= 0 && color < 256)
		color = 0xFF0000 + (color << 8);
	else if (color >= 256 && color < 512)
		color = 0xFFFF00 - ((color % 256) << 16);
	else if (color >= 512 && color < 768)
		color = 0x00FF00 + ((color % 256));
	else if (color >= 512 && color < 1024)
		color = 0x00FFFF - ((color % 256) << 8);
	else if (color >= 512 && color < 1280)
		color = 0x0000FF + ((color % 256) << 16);
	else if (color >= 512 && color < 1536)
		color = 0xFF00FF - ((color % 256));
	return (color);
}

int		scalar(int i, t_cmp_fr *fr, t_color *clr)
{
	int	color;

	(void)clr;
	if (i < fr->iter / 2)
	{
		color = (0xFF * ((fr->iter / 2) - i) / (fr->iter / 2));
		color += (0xFF * (i + 1) / (fr->iter / 2)) << 8;
	}
	else
	{
		color = (0xFF * (fr->iter - i) / (fr->iter / 2)) << 8;
		color += (0xFF * (i - (fr->iter / 2)) / (fr->iter / 2)) << 16;
	}
	return (color);
}

int		rainbow(int i, t_cmp_fr *fr, t_color *color)
{
	(void)fr;
	return (color_select(color->color, i * 8));
}

int		seuss(int i, t_cmp_fr *fr, t_color *color)
{
	(void)fr;
	(void)color;
	if (i % 5 == 0)
		return (0x77ABFF);
	else if (i % 5 == 1)
		return (0xDBA213);
	else if (i % 5 == 2)
		return (0x44E575);
	else if (i % 5 == 3)
		return (0xCF8BF4);
	else
		return (0xF7F451);
}

void	shuffle_mode(t_color *color)
{
	color->mode++;
	if (color->mode > color->max_modes)
		color->mode = 1;
	if (color->mode == 1)
		color->get_color = &scalar;
	if (color->mode == 2)
		color->get_color = &seuss;
	if (color->mode == 3)
		color->get_color = &rainbow;
	if (color->mode == 4)
		color->get_color = &pulse;
	if (color->mode == 5)
		color->get_color = &abstract;
}
