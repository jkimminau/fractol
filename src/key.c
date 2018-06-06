/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:57:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 19:07:24 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_keys(int key, t_mlx *mlx)
{
	if (key == 6 || (key >= 18 && key <= 20))
	{
		if (key != 6)
			mlx->frac = key - 17;;
		free (mlx->fr);
		mlx->fr = init_cmp_fr(mlx->frac, mlx);
	}
	if (key == 8)
		shuffle_mode(mlx->color);
	if (key == 49)
		mlx->color->rainbow = (mlx->color->rainbow == 1) ? 0 : 1;
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (key == 69)
		mlx->fr->iter += 10;
	if (key == 78 && mlx->fr->iter - 20 > 0)
		mlx->fr->iter -= 10;
	if (key == 123 || key == 124)
		translate_x(((key == 123) ? -1 : 1), mlx);
	if (key == 125 || key == 126)
		translate_y(((key == 125) ? -1 : 1), mlx);
	if (key == 12 || key == 13)
		zoom(((key == 12) ? 1 : -1), mlx);
	render(mlx);
	return (0);
}
