/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:11:47 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 22:26:47 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <pthread.h>

t_mandelbrot	*init_mandelbrot(void)
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

void			iterate(t_mandelbrot m, t_mlx *mlx, int x, int y)
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
		z_i = (2 * z_r * z_i) + m.c_i;
		z_r = z_r2 - z_i2 + m.c_r;
		i++;
	}
	img_pixel_put(mlx->img, x, y, get_color(i, mlx->iter));
}


void			*draw_thread(void *arg)
{
	t_mlx			*mlx;
	t_mandelbrot	m;
	int				y;
	int				x;

	mlx = (t_mlx *)arg;
	m = *(mlx->mdl);
	y = mlx->img->thread;
	printf("y = %d\n", y);
	while (y < WIN_LEN)
	{
		m.c_i = m.max_i - ((double)y * m.scale_i);
		x = 0;
		while (x < WIN_WID)
		{
			m.c_r = m.min_r + ((double)x * m.scale_r);
			iterate(m, mlx, x, y);
			x++;
		}
		y += 8;
	}
	return (NULL);
}

void			mandelbrot(t_mlx *mlx)
{
	pthread_t	tid[8];
	int			i;

	i = 0;
	mlx->img->thread = 0;
	while (mlx->img->thread < 8)
	{
		pthread_create(&(tid[i++]), NULL, draw_thread, (void *)mlx);
		mlx->mdl->y++;
	}
	i = 0;
	while (i < 8)
		pthread_join(tid[i++], NULL);

	/*t_mandelbrot	*m;

	m = mlx->mdl;
	m->y = 0;
	while (m->y < WIN_LEN)
	{
		m->c_i = m->max_i - ((double)m->y * m->scale_i);
		m->x = 0;
		while (m->x < WIN_WID)
		{
			m->c_r = m->min_r + ((double)m->x * m->scale_r);
			iterate(m, mlx, m->x, m->y);
			m->x++;
		}
		m->y += 8;
	}*/
	if (mlx->cl == 1)
		center_lines(mlx);
}
