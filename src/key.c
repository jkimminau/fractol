/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:57:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 16:11:46 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_keys(int key, t_mlx *mlx)
{
	if (key == 6)
	{
		mlx->mdl->min_r = -2.25;
		mlx->mdl->max_r = 2.25;
		mlx->mdl->min_i = -1.125;
		mlx->mdl->max_i = mlx->mdl->min_i
			+ (mlx->mdl->max_r - mlx->mdl->min_r) * WIN_LEN / WIN_WID;
	}
	if (key == 49)
		mlx->cl = (mlx->cl == 1) ? 0 : 1;
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (key == 69)
		mlx->iter += 10;
	if (key == 78 && mlx->iter - 10 > 0)
		mlx->iter -= 10;
	if (key == 123 || key == 124)
		translate_x(((key == 123) ? -1 : 1), mlx);
	if (key == 125 || key == 126)
		translate_y(((key == 125) ? -1 : 1), mlx);
	if (key == 12 || key == 13)
		zoom(((key == 12) ? 1 : -1), mlx);
	render(mlx);
	//printf("key = %d\n", key);
	printf("left bound: %f\tright bound: %f\n", mlx->mdl->min_r, mlx->mdl->max_r);
	printf("upper bound: %f\tlower bound: %f\n", mlx->mdl->min_i, mlx->mdl->max_i);
	printf("iter = %d\n", mlx->iter);
	return (0);
}
