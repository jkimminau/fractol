/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 18:20:19 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_events(t_mlx *mlx)
{
	if (mlx->img->rainbow)
	{
		mlx->img->color = color_increment(mlx->img->color, 10);
		render(mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if ((argc != 2) || (!ft_strcmp(argv[1], "1") && !ft_strcmp(argv[1], "2") && !ft_strcmp(argv[1], "3")))
	{
		ft_putendl("usage: ./fractol [option num]");
		ft_putendl("1) mandelbrot");
		ft_putendl("2) julia");
		exit(0);
	}
	if (!(mlx = init_mlx(argv[1])))
	{
		ft_putendl("error initializing mlx");
		exit(0);
	}
	render(mlx);
	mlx_key_hook(mlx->win, handle_keys, mlx);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	mlx_hook(mlx->win, 6, 1L<<6, mouse_move, mlx);
	mlx_loop_hook(mlx->mlx, loop_events, mlx);
	mlx_loop(mlx->mlx);
	mlx_free(mlx, "");
	return (0);
}
