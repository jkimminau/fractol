/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:06:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 18:03:48 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_mandelbrot	*init_julia(void)
{
	t_mandelbrot	*tmp;

	if (!(tmp = (t_mandelbrot *)malloc(sizeof(t_mandelbrot))))
		return (0);
	tmp->min_r = -1.65;
	tmp->max_r = 1.65;
	tmp->min_i = -1.15;
	tmp->max_i = tmp->min_i + (tmp->max_r - tmp->min_r) * WIN_LEN / WIN_WID;
	tmp->diff_r = tmp->max_r - tmp->min_r;
	tmp->diff_i = tmp->max_i - tmp->min_i;
	tmp->scale_r = (tmp->max_r - tmp->min_r) / (WIN_WID - 1);
	tmp->scale_i = (tmp->max_i - tmp->min_i) / (WIN_LEN - 1);
	return (tmp);
}

void			iterate_j(t_mandelbrot *m, t_mlx *mlx)
{
	intmax_t	i;
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;

	z_r = m->c_r;
	z_i = m->c_i;
	i = 0;
	while (i < mlx->iter)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 > 4)
			break ;
		z_i = (2 * z_r * z_i) + mlx->mdl->k_i;
		z_r = z_r2 - z_i2 + mlx->mdl->k_r;
		i++;
	}
	img_pixel_put(mlx->img, m->x, m->y, rainbow(i, mlx->img));
}

void			julia(t_mlx *mlx)
{
	t_mandelbrot	*m;

	m = mlx->mdl;
	m->y = 0;
	while (m->y < WIN_LEN)
	{
		m->c_i = m->max_i + mlx->img->y	- ((double)m->y * m->scale_i);
		m->x = 0;
		while (m->x < WIN_WID)
		{
			m->c_r = m->min_r + mlx->img->x	+ ((double)m->x * m->scale_r);
			iterate_j(m, mlx);
			m->x++;
		}
		m->y++;
	}
	if (mlx->cl == 1)
		center_lines(mlx);
}
