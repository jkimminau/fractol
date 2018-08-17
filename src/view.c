/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:22:02 by jkimmina          #+#    #+#             */
/*   Updated: 2018/08/17 14:45:17 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	translate_x(int x, t_mlx *mlx)
{
	if (x == 1)
	{
		mlx->fr->max_r += mlx->fr->diff_r * 0.05;
		mlx->fr->min_r += mlx->fr->diff_r * 0.05;
	}
	if (x == -1)
	{
		mlx->fr->max_r -= mlx->fr->diff_r * 0.05;
		mlx->fr->min_r -= mlx->fr->diff_r * 0.05;
	}
}

void	translate_y(int y, t_mlx *mlx)
{
	if (y == 1)
	{
		mlx->fr->max_i += mlx->fr->diff_i * 0.05;
		mlx->fr->min_i += mlx->fr->diff_i * 0.05;
	}
	if (y == -1)
	{
		mlx->fr->max_i -= mlx->fr->diff_i * 0.05;
		mlx->fr->min_i -= mlx->fr->diff_i * 0.05;
	}
}

void	zoom(int i, t_mlx *mlx)
{
	double	r_fact;
	double	i_fact;

	if (i == -1)
	{
		r_fact = mlx->fr->diff_r * 0.05;
		i_fact = mlx->fr->diff_i * 0.05;
	}
	else
	{
		r_fact = mlx->fr->diff_r / (2 * 9);
		i_fact = mlx->fr->diff_i / (2 * 9);
	}
	mlx->fr->max_r += (i * r_fact);
	mlx->fr->min_r -= (i * r_fact);
	mlx->fr->max_i += (i * i_fact);
	mlx->fr->min_i -= (i * i_fact);
	mlx->fr->diff_r = mlx->fr->max_r - mlx->fr->min_r;
	mlx->fr->diff_i = mlx->fr->max_i - mlx->fr->min_i;
	mlx->fr->scale_r = mlx->fr->diff_r / (WIN_WID - 1);
	mlx->fr->scale_i = mlx->fr->diff_i / (WIN_LEN - 1);
}
