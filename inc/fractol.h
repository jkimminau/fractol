/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/03 22:43:48 by jkimmina         ###   ########.fr       */
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

t_mandelbrot	*init_mandelbrot();
void			mandelbrot(t_mlx *mlx);
t_mandelbrot	*init_julia();
void			julia(t_mlx *mlx);
t_mandelbrot	*init_burningship();
void			burningship(t_mlx *mlx);
t_mandelbrot	*init_sin();
void			sinusoidal(t_mlx *mlx);
int				color_increment(int color, int num);
int				get_color(int i, int iter);
int				rainbow(int i, t_img *img);

#endif
