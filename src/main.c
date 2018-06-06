/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/06 15:49:30 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_events(t_mlx *mlx)
{
	if (mlx->color->rainbow && (mlx->color->mode == 3 || mlx->color->mode == 4))
	{
		mlx->color->color += 50;
		if (mlx->color->color >= 1536)
			mlx->color->color = 0;
		render(mlx);
	}
	if (mlx->color->mode == 4)
	{
		mlx->color->pulse += 1;
		if (mlx->color->pulse > mlx->fr->iter)
			mlx->color->pulse = 0;
		render(mlx);
	}
	return (0);
}

int		get_option(int ac, char **av)
{
	if (ac > 2)
		return (-1);
	if (ac == 1 || ft_strcmp(av[1], "1") == 0)
		return (1);
	if (ft_strcmp(av[1], "2") == 0)
		return (2);
	if (ft_strcmp(av[1], "3") == 0)
		return (3);
	return (-1);
}

void	print_controls(void)
{
	ft_putendl("/***********************CONTROLS*************************\\");
	ft_putendl("*  1) mandelbrot set                                     *");
	ft_putendl("*  2) julia set                                          *");
	ft_putendl("*  3) burningship set                                    *");
	ft_putendl("* Q: Zoom out  W: Zoom in  (or mouse wheel)              *");
	ft_putendl("* Arrow keys: move up/down/left/right                    *");
	ft_putendl("* +: Increase iterations   -: Decrease iterations        *");
	ft_putendl("* Z: reset current set   C: change color mode            *");
	ft_putendl("* Space: Scrolls through colors in rainbow mode          *");
	ft_putendl("* Left click: Lock Julia set                             *");
	ft_putendl("\\*******************************************************/");
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	int		option;

	if ((option = get_option(ac, av)) == -1)
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
	print_controls();
	render(mlx);
	mlx_key_hook(mlx->win, handle_keys, mlx);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_loop_hook(mlx->mlx, loop_events, mlx);
	mlx_loop(mlx->mlx);
	mlx_free(mlx, "");
	return (0);
}
