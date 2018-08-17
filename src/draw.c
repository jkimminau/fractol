/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:21 by jkimmina          #+#    #+#             */
/*   Updated: 2018/08/17 14:43:16 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WID && y >= 0 && y < WIN_LEN)
		*(int *)(img->data_addr + ((x + y * WIN_WID) * img->bpp)) = color;
}

void	*draw_thread(void *arg)
{
	t_mlx		*mlx;
	t_cmp_fr	fr;
	int			y;
	int			x;

	mlx = (t_mlx *)((t_thread *)arg)->mlx;
	fr = *(mlx->fr);
	y = ((t_thread *)arg)->i;
	while (y < WIN_LEN)
	{
		fr.c_i = fr.max_i - ((double)y * fr.scale_i);
		x = 0;
		while (x < WIN_WID)
		{
			fr.c_r = fr.min_r + ((double)x * fr.scale_r);
			(*mlx->iterate)(fr, mlx, x, y);
			x++;
		}
		y += THREADS;
	}
	return (NULL);
}

void	render(t_mlx *mlx)
{
	t_thread	list[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		list[i].i = i;
		list[i].mlx = mlx;
		pthread_create(&(list[i]).tid, NULL, draw_thread, &list[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(list[i++].tid, NULL);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->ptr, 0, 0);
}
