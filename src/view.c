/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:22:02 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 20:13:45 by jkimmina         ###   ########.fr       */
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

void	zoom(int i, t_mlx *mlx)
{
	double	r_fact;
	double	i_fact;

	if (i == -1)
	{
		r_fact = mlx->mdl->diff_r * 0.05;
		i_fact = mlx->mdl->diff_i * 0.05;
	}
	else
	{
		r_fact = mlx->mdl->diff_r / (2 * 9);
		i_fact = mlx->mdl->diff_i / (2 * 9);
	}
	mlx->mdl->max_r += (i * r_fact);
	mlx->mdl->min_r -= (i * r_fact);
	mlx->mdl->max_i += (i * i_fact);
	mlx->mdl->min_i -= (i * i_fact);
}

void	render(t_mlx *mlx)
{
	mlx->mdl->diff_r = mlx->mdl->max_r - mlx->mdl->min_r;
	mlx->mdl->diff_i = mlx->mdl->max_i - mlx->mdl->min_i;
	mlx->mdl->scale_r = (mlx->mdl->max_r - mlx->mdl->min_r) / (WIN_WID - 1);
	mlx->mdl->scale_i = (mlx->mdl->max_i - mlx->mdl->min_i) / (WIN_LEN - 1);
	mlx_clear_window(mlx->mlx, mlx->win);
	(*mlx->fractal)(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->ptr, 0, 0);
}
