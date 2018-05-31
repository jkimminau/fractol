/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:59:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/30 18:13:22 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	printf("button: %d\n", button);
	if (button == 5)
		mlx->img->zoom++;
	if (button == 4 && mlx->img->zoom > 1)
		mlx->img->zoom--;
	printf("r_diff: %f\ti_diff: %f\n", mlx->mdl->diff_r, mlx->mdl->diff_i);
	printf("left bound: %f\tright bound: %f\n", mlx->mdl->min_r, mlx->mdl->max_r);
	printf("upper bound: %f\tlower bound: %f\n", mlx->mdl->min_i, mlx->mdl->max_i);
	printf("zoom = %d\n", mlx->img->zoom);	
	
	return (0);
}
