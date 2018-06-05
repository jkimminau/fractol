/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 16:15:49 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_events(t_mlx *mlx)
{
	if (mlx->color->rainbow && mlx->color->mode == 3)
	{
		mlx->color->color = color_increment(mlx->color->color, 10);
		render(mlx);
	}
	return (0);
}

int		get_option(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (ft_strcmp(av[1], "1") == 0)
		return (1);
	if (ft_strcmp(av[1], "2") == 0)
		return (2);
	if (ft_strcmp(av[1], "3") == 0)
		return (3);
	return (-1);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	int		option;

	if	((option = get_option(ac, av)) == -1)
	{
		ft_putendl("usage: ./fractol [option num]");
		ft_putendl("1) mandelbrot");
		ft_putendl("2) julia");
		ft_putendl("3) burningship");
		exit(0);
	}
	if (!(mlx = init_mlx(option)))
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
