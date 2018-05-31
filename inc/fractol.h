/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/30 20:43:35 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WID	1000
# define WIN_LEN	500
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../X11_minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include "init.h"
# include "draw.h"
# include "key.h"
# include "mouse.h"

void			iter_triforce(t_mlx *mlx);
void			triforce(t_mlx *mlx);
t_mandelbrot	*init_mandelbrot(t_img *img);
void			mandelbrot(t_mlx *mlx);

#endif
