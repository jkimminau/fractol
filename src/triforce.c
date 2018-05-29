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
	int		j;
	int		y;
	//int		c;

	i = 0;
	y = 0;
	while (i < ft_pow(2, mlx->iter))
	{
		j = 0;
		while (j < i + 1)
		{
			//c = 500 / (2 * (mlx->iter + 1));
			y = (500 / ft_pow(2, mlx->iter + 1)) + (i * 500 / ft_pow(2, mlx->iter));
			//y = (500 / ft_pow(2, mlx->iter + 1)) + (i * 500 / ft_pow(2, mlx->iter));
			printf("y = %d ", y);
			//x = 
			/*while (--c)
			{
				y++;
			}*/
			j++;
		}
		i++;
	}
	//y = 250 + (500 / ft_pow(2, mlx->iter)) + (i * 500 / ft_pow(2, mlx->iter - 1));
	mlx->iter++;
	printf("\n");
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
			img_pixel_put(mlx->img, (x + (499 - y) / 2), y, 0x0000FF);
			x++;
		}
		y++;
	}
}
