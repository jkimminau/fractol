/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:56:28 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 21:28:14 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_mlx	*mlx_free(t_mlx *mlx, char *errmsg)
{
	ft_putstr(errmsg);
	if (mlx->mlx != 0)
		free(mlx->mlx);
	//if (mlx->win)
		//free(mlx->win);
	if (mlx != 0)
		free(mlx);
	sleep(100);
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
	return (img);
}

t_color	*init_color()
{
	t_color		*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->mode = 1;
	color->max_modes = 4;
	color->color = 0;
	color->pulse = 0;
	color->rainbow = 0;
	color->get_color = &scalar;
	return (color);
}

t_cmp_fr	*init_cmp_fr(int frac, t_mlx *mlx)
{
	t_cmp_fr	*fr;

	if (frac == 1)
	{
		mlx->iterate = &iterate_mdl;
		fr = (init_mandelbrot(mlx->img));
	}
	if (frac == 2)
	{
		mlx->iterate = &iterate_jul;
		fr = (init_julia(mlx->img));
	}
	if (frac == 3)
	{
		mlx->iterate = &iterate_brn;
		fr = (init_burningship(mlx->img));
	}
	return (fr);
}

t_mlx		*init_mlx(int frac)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->mlx = mlx_init()))
		return (mlx_free(mlx, "error initializing mlx pointer\n"));
	mlx_free(mlx, "");
	if (!(mlx->win = mlx_new_window(mlx->mlx,
					WIN_WID, WIN_LEN, "fractol - 42")))
		return (mlx_free(mlx, "error initializing window pointer\n"));
	if (!(mlx->img = init_img(mlx->mlx)))
		return (mlx_free(mlx, "error initializing image pointer\n"));
	if (!(mlx->fr = init_cmp_fr(frac, mlx)))
		return (mlx_free(mlx, "error initializing frac ptr\n"));
	if (!(mlx->color = init_color()))
		return (mlx_free(mlx, "error initializing color ptr\n"));
	mlx->frac = frac;
	mlx->mouselock = 0;
	return (mlx);
}
