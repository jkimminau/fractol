/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:21 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/30 19:10:57 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*int		getcolor(t_mlx *mlx, t_point l)
{
	if (mlx->party)
		return (color_increment(mlx->color, l.z + l.y + l.x));
	else if (mlx->minimal)
		return (mlx->color * l.z / mlx->map->maxz);
	else if (mlx->surge)
		return (mlx->color * (mlx->surge == (int)l.z));
	else
		return (color_increment(mlx->color, l.z * 10));
}*/

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
