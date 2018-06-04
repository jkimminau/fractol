/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:59:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 23:08:01 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_LEN)
		return (0);
	mlx->mdl->k_r = mlx->mdl->min_r + (x * mlx->mdl->scale_r);
	mlx->mdl->k_i = mlx->mdl->min_i + (y * mlx->mdl->scale_i);
	render(mlx);
	return (0);
}

int		handle_mouse(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		zoom(((button == 5) ? -1 : 1), mlx);
	render(mlx);
	return (0);
}
