#include <fractol.h>

t_mandelbrot	*init_mandelbrot(t_img *img)
{
	t_mandelbrot	*tmp;

	(void)img;
	if (!(tmp = (t_mandelbrot *)malloc(sizeof(t_mandelbrot))))
		return (0);
	tmp->min_r = -2.5;
	tmp->max_r = 1.5;
	tmp->min_i = -1.2;
	tmp->max_i = tmp->min_i + (tmp->max_r - tmp->min_r) * WIN_LEN / WIN_WID;
	tmp->diff_r = tmp->max_r - tmp->min_r;
	tmp->diff_i = tmp->max_i - tmp->min_i;
	tmp->scale_r = (tmp->max_r - tmp->min_r) / (WIN_WID - 1);
	tmp->scale_i = (tmp->max_i - tmp->min_i) / (WIN_LEN - 1);
	return (tmp);
}

void	center_lines(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < WIN_WID)
		img_pixel_put(mlx->img, i++, WIN_LEN / 2, 0xFFFFFF);
	i = 0;
	while (i < WIN_LEN)
		img_pixel_put(mlx->img, WIN_WID / 2, i++, 0xFFFFFF);
}

int	get_color(int i, int iterations)
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

void	iterate(t_mandelbrot *m, t_mlx  *mlx)
{
	intmax_t	i;
	int		iterations;
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;

	z_r = m->c_r;
	z_i = m->c_i;
	i = 0;
	iterations = 250;
	while (i < iterations)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 > 4)
			break;
		z_i = (2 * z_r * z_i) + m->c_i;
		z_r = z_r2 - z_i2 + m->c_r;
		i++;
	}
	img_pixel_put(mlx->img, m->x, m->y, get_color(i, iterations));	
}

void	mandelbrot(t_mlx *mlx)
{
	t_mandelbrot	*m;

	m = mlx->mdl;
	m->min_r = -2.5 + (mlx->img->zoom);
	m->scale_r = (m->max_r - m->min_r) / (WIN_WID - 1);
	m->scale_i = (m->max_i - m->min_i) / (WIN_LEN - 1);
	m->y = 0;
	while (m->y < WIN_LEN)
	{
		m->c_i = m->max_i + ((double)mlx->img->y / mlx->img->zoom) - ((double)m->y * m->scale_i);
		m->x = 0;
		while (m->x < WIN_WID)
		{
			m->c_r = m->min_r + ((double)mlx->img->x / mlx->img->zoom) + ((double)m->x * m->scale_r);
			iterate(m, mlx);
			m->x++;
		}
		m->y++;
	}
	center_lines(mlx);
}