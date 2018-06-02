/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:59:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 16:07:43 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		zoom(((button == 5) ? -1 : 1), mlx);
	render(mlx);
	printf("r_diff: %f\ti_diff: %f\n", mlx->mdl->diff_r, mlx->mdl->diff_i);
	printf("left bound: %f\tright bound: %f\n",
			mlx->mdl->min_r, mlx->mdl->max_r);
	printf("upper bound: %f\tlower bound: %f\n",
			mlx->mdl->min_i, mlx->mdl->max_i);
	return (0);
}
