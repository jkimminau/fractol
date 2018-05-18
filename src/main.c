/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 19:56:07 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_events(t_mlx *mlx)
{
	(void)mlx;
	/*mlx->color = color_increment(mlx->color, 4 + (mlx->party * 64));
	if (mlx->surge != 0)
	{
		mlx->ss = (mlx->ss > 1) ? 1 : mlx->ss;
		mlx->ss = (mlx->ss < 0) ? 0 : mlx->ss;
		if (mlx->surge <= 1)
			mlx->surge = mlx->map->maxz;
		else
			mlx->surge -= mlx->ss;
	}*/
	//render(mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void)argv;
	if (argc == 1)
	{
		if (!(mlx = init_mlx()))
		{
			ft_putendl("error initializing mlx");
			exit(0);
		}
		triforce(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->ptr, 0, 0);
		mlx_key_hook(mlx->win, handle_keys, mlx);
		//mlx_loop_hook(mlx->mlx, loop_events, mlx);
		mlx_loop(mlx->mlx);
		mlx_free(mlx, "");
	}
	return (0);
}
