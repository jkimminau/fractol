/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:59:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 18:51:30 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_LEN || mlx->frac != 2 || mlx->mouselock == 1)
		return (0);
	mlx->fr->k_r = mlx->fr->min_r + (x * mlx->fr->scale_r);
	mlx->fr->k_i = mlx->fr->min_i + (y * mlx->fr->scale_i);
	render(mlx);
	return (0);
}

int		handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 1)
		mlx->mouselock = (mlx->mouselock == 1) ? 0 : 1;
	if (button == 5 || button == 4)
		zoom(((button == 5) ? -1 : 1), mlx);
	render(mlx);
	return (0);
}
