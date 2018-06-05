/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:31:30 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 16:33:54 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

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
		color += (0xFF * (i + 1 - (fr->iter / 2)) / (fr->iter / 2)) << 16;
	}
	return (color);
}

int		rainbow(int i, t_cmp_fr *fr, t_color *color)
{
	(void)fr;
	return (color_increment(color->color, i * 8));
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

}
