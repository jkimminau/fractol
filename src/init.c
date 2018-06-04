/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:56:28 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 23:05:15 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_mlx	*mlx_free(t_mlx *mlx, char *errmsg)
{
	ft_putstr(errmsg);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->win)
		free(mlx->win);
	if (mlx)
		free(mlx);
	mlx->cl = 0;
	return (0);
}

t_img	*init_img(void *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(img->ptr = mlx_new_image(mlx, WIN_WID, WIN_LEN)))
		return (0);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	img->bpp /= 8;
	img->color = 0x0000FF;
	img->rainbow = 0;
	return (img);
}

t_mlx	*init_mlx(char *f)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->mlx = mlx_init()))
		return (mlx_free(mlx, "error initializing mlx pointer\n"));
	if (!(mlx->win = mlx_new_window(mlx->mlx,
					WIN_WID, WIN_LEN, "fractol - 42")))
		return (mlx_free(mlx, "error initializing window pointer\n"));
	if (!(mlx->img = init_img(mlx->mlx)))
		return (mlx_free(mlx, "error initializing image pointer\n"));
	if (ft_strcmp(f, "1") == 0)
	{
		mlx->fractal = &mandelbrot;
		mlx->mdl = (init_mandelbrot(mlx->img));
	}
	if (ft_strcmp(f, "2") == 0)
	{
		mlx->fractal = &julia;
		mlx->mdl = (init_julia(mlx->img));
	}
	if (ft_strcmp(f, "3") == 0)
	{
		mlx->fractal = &burningship;
		mlx->mdl = (init_burningship(mlx->img));
	}
	if (!(mlx->mdl))
		return (mlx_free(mlx, "error initializing jul ptr\n"));
	mlx->iter = 100;
	return (mlx);
}
