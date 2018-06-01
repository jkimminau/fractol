/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:22:02 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/01 16:49:38 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <view.h>

void	translate_x(int x, t_mlx *mlx)
{
	if (x == 1)
	{
		mlx->mdl->max_r += mlx->mdl->diff_r * 0.05;
		mlx->mdl->min_r += mlx->mdl->diff_r * 0.05;
	}
	if (x == -1)
	{
		mlx->mdl->max_r -= mlx->mdl->diff_r * 0.05;
		mlx->mdl->min_r -= mlx->mdl->diff_r * 0.05;
	}
}

void	translate_y(int y, t_mlx *mlx)
{
	if (y == 1)
	{
		mlx->mdl->max_i += mlx->mdl->diff_i * 0.05;
		mlx->mdl->min_i += mlx->mdl->diff_i * 0.05;
	}
	if (y == -1)
	{
		mlx->mdl->max_i -= mlx->mdl->diff_i * 0.05;
		mlx->mdl->min_i -= mlx->mdl->diff_i * 0.05;
	}
}
