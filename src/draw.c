/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:21 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 18:18:59 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WID && y >= 0 && y < WIN_LEN)
		*(int *)(img->data_addr + ((x + y * WIN_WID) * img->bpp)) = color;
}

void	center_lines(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < WIN_WID)
		img_pixel_put(mlx->img, i++, WIN_LEN / 2, 0xFFFFFF);
	i = 0;
	while (i < WIN_LEN)
		img_pixel_put(mlx->img, WIN_WID / 2, i++, 0xFFFFFF);
}
