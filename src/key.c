/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:57:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 19:56:00 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_keys(int key, t_mlx *mlx)
{
	printf("key = %d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	//if (key == 49)	//space
	if (key == 123 || key == 124)
		mlx->img->x += (key > 123) ? 1 : -1;
	if (key == 125 || key == 126)
		mlx->img->y += (key == 125) ? -1 : 1;
	if (key == 12 && mlx->img->zoom > 1)
	{
		mlx->mdl->min_r -= (mlx->mdl->diff_r / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->max_r += (mlx->mdl->diff_r / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->min_i -= (mlx->mdl->diff_i / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->max_i = mlx->mdl->min_i + (mlx->mdl->max_r - mlx->mdl->min_r) * WIN_LEN / WIN_WID;
		mlx->img->zoom--;
	}
	if (key == 13)
	{
		mlx->img->zoom++;
		mlx->mdl->min_r += (mlx->mdl->diff_r / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->max_r -= (mlx->mdl->diff_r / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->min_i += (mlx->mdl->diff_i / (4 * (mlx->img->zoom - 1)));
		mlx->mdl->max_i = mlx->mdl->min_i + (mlx->mdl->max_r - mlx->mdl->min_r) * WIN_LEN / WIN_WID;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->ptr, 0, 0);
	printf("r_diff: %f\ti_diff: %f\n", mlx->mdl->diff_r, mlx->mdl->diff_i);
	printf("left bound: %f\tright bound: %f\n", mlx->mdl->min_r, mlx->mdl->max_r);
	printf("upper bound: %f\tlower bound: %f\n", mlx->mdl->min_i, mlx->mdl->max_i);
	printf("zoom = %d\n", mlx->img->zoom);	
	return (0);
}
