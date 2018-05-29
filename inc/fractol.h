/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 19:52:49 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WID	1800
# define WIN_LEN	1000
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../X11_minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
//# include "map.h"
# include "init.h"
# include "draw.h"
//# include "view.h"
# include "key.h"

void		iter_triforce(t_mlx *mlx);
void		triforce(t_mlx *mlx);
t_mandelbrot	*init_mandelbrot(t_img *img);
void		mandelbrot(t_mlx *mlx);
int		get_color(int i, int iteractions); 

#endif
