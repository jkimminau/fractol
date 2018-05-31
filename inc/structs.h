/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/30 20:04:46 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_mandelbrot
{
	int		x;
	int		y;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		diff_r;
	double		diff_i;
	double		c_r;
	double		c_i;
	double		scale_r;
	double		scale_i;
}			t_mandelbrot;

typedef struct		s_img
{
	void		*ptr;
	char		*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		x;
	int		y;
	int		zoom;
}			t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				iter;
	t_mandelbrot	*mdl;
	int				cl;
}				t_mlx;

#endif
