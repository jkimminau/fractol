/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:11:47 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 21:43:56 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

t_mandelbrot	*init_sin(void)
{
	t_mandelbrot	*tmp;

	if (!(tmp = (t_mandelbrot *)malloc(sizeof(t_mandelbrot))))
		return (0);
	tmp->min_r = -2.15;
	tmp->max_r = 1.15;
	tmp->min_i = -1.15;
	tmp->max_i = tmp->min_i + (tmp->max_r - tmp->min_r) * WIN_LEN / WIN_WID;
	tmp->diff_r = tmp->max_r - tmp->min_r;
	tmp->diff_i = tmp->max_i - tmp->min_i;
	tmp->scale_r = (tmp->max_r - tmp->min_r) / (WIN_WID - 1);
	tmp->scale_i = (tmp->max_i - tmp->min_i) / (WIN_LEN - 1);
	return (tmp);
}

int				get_color_s(int i, int iterations)
{
	int	color;

	if (i < (iterations / 2))
		color = (0xFF * (i + 1) / (iterations / 2)) << 16;
	else
	{
		color = (0xFF * (i + 1 - (iterations / 2)) / (iterations / 2));
		color = color << 8;
		color += (0xFF * (i + 1 - (iterations / 2)) / (iterations / 2));
		color += 0xFF0000;
	}
	return (color);
}

void			func_list(int i, int *x, int *y)
{
	if (i == 0)
	{
		*x /= 2;
		*y /= 2;
	}
	if (i == 1)
	{
		*x = (*x + 1) / 2;
		*y /= 2;
	}
	if (i == 2)
	{
		*x /= 2;
		*y = (*y + 1) / 2;
	}
}

void			iterate_s(t_mandelbrot *m, t_mlx *mlx)
{
	intmax_t	i;
	int			x;
	int			y;

	x = m->x;
	y = m->y;
	i = 0;
	while (i < mlx->iter)
	{
		func_list(i % 3, &x, &y);
		if (i > 19)
			img_pixel_put(mlx->img, x, y, 0xFFFFFF);
		i++;
	}
}

void			sinusoidal(t_mlx *mlx)
{
	t_mandelbrot	*m;

	m = mlx->mdl;
	m->y = 0;
	while (m->y < WIN_LEN)
	{
		m->c_i = m->max_i - ((double)m->y * m->scale_i);
		m->x = 0;
		while (m->x < WIN_WID)
		{
			m->c_r = m->min_r + ((double)m->x * m->scale_r);
			iterate_s(m, mlx);
			m->x++;
		}
		m->y++;
	}
	if (mlx->cl == 1)
		center_lines(mlx);
}
