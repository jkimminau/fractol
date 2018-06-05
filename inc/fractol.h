/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 15:03:45 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WID	700
# define WIN_LEN	500
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "../X11_minilibx_macos/mlx.h"
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
