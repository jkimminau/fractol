/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:08:11 by jkimmina          #+#    #+#             */
/*   Updated: 2018/08/17 14:00:11 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		pulse(int i, t_cmp_fr *fr, t_color *color)
{
	(void)fr;
	if (i == color->pulse)
	{
		if (color->rainbow)
			return (color_select(color->color, 0));
		return (color_select(color->color, i * 8));
	}
	return (0);
}

int		abstract(int i, t_cmp_fr *fr, t_color *color)
{
	(void)fr;
	return (0xFFFFFF - (0xFFFFFF * i / color->max_modes));
}
