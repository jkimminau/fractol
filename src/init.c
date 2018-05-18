/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:56:28 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 19:54:06 by jkimmina         ###   ########.fr       */
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
	return (0);
}

t_point			*newpoint(void)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (0);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return (point);
}

t_img	*init_img(void *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(img->ptr = mlx_new_image(mlx, WIN_WID, WIN_LEN)))
		return (0);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size, &img->endian);
	img->bpp /= 8;
	return (img);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->mlx = mlx_init()))
		return (mlx_free(mlx, "error initializing mlx pointer\n"));
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_WID, WIN_LEN, "fdf - 42")))
		return (mlx_free(mlx, "error initializing window pointer\n"));
	if (!(mlx->img = init_img(mlx->mlx)))
		return (mlx_free(mlx, "error initializing image pointer\n"));
	mlx->iter = 0;
	return (mlx);
}
