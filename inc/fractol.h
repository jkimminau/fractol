/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/06 17:10:26 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WID	1400
# define WIN_LEN	1000
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include "init.h"
# include "draw.h"
# include "view.h"
# include "key.h"
# include "mouse.h"
# include "color.h"

t_cmp_fr		*init_mandelbrot();
void			iterate_mdl(t_cmp_fr fr, t_mlx *mlx, int x, int y);
t_cmp_fr		*init_julia();
void			iterate_jul(t_cmp_fr fr, t_mlx *mlx, int x, int y);
t_cmp_fr		*init_burningship();
void			iterate_brn(t_cmp_fr fr, t_mlx *mlx, int x, int y);

#endif
