/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:06:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/04 13:25:52 by jkimmina         ###   ########.fr       */
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

void			iterate_jul(t_mandelbrot m, t_mlx *mlx, int x, int y)
{
	intmax_t	i;
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;

	z_r = m.c_r;
	z_i = m.c_i;
	i = 0;
	while (i < mlx->iter)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 > 4)
			break ;
		z_i = (2 * z_r * z_i) + m.k_i;
		z_r = z_r2 - z_i2 + m.k_r;
		i++;
	}
	img_pixel_put(mlx->img, x, y, get_color(i, mlx->iter));
	//img_pixel_put(mlx->img, x, y, rainbow(i, mlx->img));
}

void			*jul_thread(void *arg)
{
	t_mlx			*mlx;
	t_mandelbrot	m;
	int				y;
	int				x;

	mlx = (t_mlx *)((t_thread *)arg)->mlx;
	m = *(mlx->mdl);
	y = ((t_thread *)arg)->i;
	while (y < WIN_LEN)
	{
		m.c_i = m.max_i -((double)y * m.scale_i);
		x = 0;
		while (x < WIN_WID)
		{
			m.c_r = m.min_r + ((double)x * m.scale_r);
			iterate_jul(m, mlx, x, y);
			x++;
		}
		y += 8;
	}
	return (NULL);
}

void			julia(t_mlx *mlx)
{
	t_thread		list[8];
	int				i;

	i = 0;
	while (i < 8)
	{
		list[i].i = i;
		list[i].mlx = mlx;
		pthread_create(&(list[i]).tid, NULL, jul_thread, &list[i]);
		i++;
	}
	i = 0;
	while (i < 8)
		pthread_join(list[i++].tid, NULL);
}
