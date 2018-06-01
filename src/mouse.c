/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:59:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/01 15:13:51 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	//printf("button: %d\n", button);
	if (button == 5)
	{
		mlx->mdl->max_r -= (mlx->mdl->diff_r) * 0.05;
		mlx->mdl->min_r += (mlx->mdl->diff_r) * 0.05;
		mlx->mdl->max_i -= (mlx->mdl->diff_i) * 0.05;
		mlx->mdl->min_i += (mlx->mdl->diff_i) * 0.05;
	}
	if (button == 4)//&& mlx->img->zoom > 1)
	{
		mlx->mdl->max_r += (mlx->mdl->diff_r) / (2 * 9);
		mlx->mdl->min_r -= (mlx->mdl->diff_r) / (2 * 9);
		mlx->mdl->max_i += (mlx->mdl->diff_i) / (2 * 9);
		mlx->mdl->min_i -= (mlx->mdl->diff_i) / (2 * 9);
	}
	mlx->mdl->diff_r = mlx->mdl->max_r - mlx->mdl->min_r;
	mlx->mdl->diff_i = mlx->mdl->max_i - mlx->mdl->min_i;
	mlx->mdl->scale_r = (mlx->mdl->max_r - mlx->mdl->min_r) / (WIN_WID - 1);
	mlx->mdl->scale_i = (mlx->mdl->max_i - mlx->mdl->min_i) / (WIN_LEN - 1);
	mlx_clear_window(mlx->mlx, mlx->win);
	mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->ptr, 0, 0);
	printf("r_diff: %f\ti_diff: %f\n", mlx->mdl->diff_r, mlx->mdl->diff_i);
	printf("left bound: %f\tright bound: %f\n", mlx->mdl->min_r, mlx->mdl->max_r);
	printf("upper bound: %f\tlower bound: %f\n", mlx->mdl->min_i, mlx->mdl->max_i);
	
	return (0);
}
