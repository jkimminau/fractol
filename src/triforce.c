/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triforce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:29:22 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 19:59:09 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_triforce(t_mlx *mlx)
{
	int		i;
	//int		x;
	int		y;

	i = 0;
	mlx->iter++;
	while (i < mlx->iter)
	{
		y = 250 + (500 / ft_pow(2, mlx->iter)) + (i * 500 / ft_pow(2, mlx->iter - 1));
		printf("y^%d = %d\n", i, y);
		i++;
	}
}

void	triforce(t_mlx *mlx)
{
	uintmax_t		x;
	uintmax_t		y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < y + 1)
		{
			img_pixel_put(mlx->img, x + (499 - y) / 2, 250 + y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
