/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:06:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 15:04:05 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_cmp_fr		*init_julia(void)
{
	t_cmp_fr	*tmp;

	if (!(tmp = (t_cmp_fr *)malloc(sizeof(t_cmp_fr))))
		return (0);
	tmp->min_r = -1.65;
	tmp->max_r = 1.65;
	tmp->min_i = -1.15;
	tmp->max_i = tmp->min_i + (tmp->max_r - tmp->min_r) * WIN_LEN / WIN_WID;
	tmp->diff_r = tmp->max_r - tmp->min_r;
	tmp->diff_i = tmp->max_i - tmp->min_i;
	tmp->scale_r = (tmp->max_r - tmp->min_r) / (WIN_WID - 1);
	tmp->scale_i = (tmp->max_i - tmp->min_i) / (WIN_LEN - 1);
	tmp->iter = 100;
	return (tmp);
}

void			iterate_jul(t_cmp_fr m, t_mlx *mlx, int x, int y)
{
	intmax_t	i;
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;

	z_r = m.c_r;
	z_i = m.c_i;
	i = 0;
	while (i < m.iter)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 > 4)
			break ;
		z_i = (2 * z_r * z_i) + m.k_i;
		z_r = z_r2 - z_i2 + m.k_r;
		i++;
	}
	img_pixel_put(mlx->img, x, y, (mlx->color->get_color)(i, mlx->fr, mlx->color));
}
