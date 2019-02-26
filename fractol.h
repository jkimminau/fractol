/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:40:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/08/17 14:36:15 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WID	1000
# define WIN_LEN	800
# define THREADS	8
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

typedef struct	s_cmp_fr
{
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
	double		k_r;
	double		k_i;
	int			iter;
}				t_cmp_fr;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_color
{
	int			mode;
	int			max_modes;
	int			color;
	int			pulse;
	int			rainbow;
	int			(*get_color)(int, t_cmp_fr *, struct s_color *);
}				t_color;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_cmp_fr	*fr;
	t_color		*color;
	int			frac;
	int			mouselock;
	void		(*iterate)(t_cmp_fr, struct s_mlx *, int, int);
}				t_mlx;

typedef struct	s_thread
{
	pthread_t		tid;
	int				i;
	t_mlx			*mlx;
}				t_thread;

t_mlx			*mlx_free(t_mlx *mlx, char *errmsg);
t_img			*init_img(void *mlx);
t_color			*init_color(void);
t_cmp_fr		*init_cmp_fr(int frac, t_mlx *mlx);
t_mlx			*init_mlx(int frac);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			*draw_thread(void *arg);
void			render(t_mlx *mlx);
t_cmp_fr		*init_mandelbrot();
void			iterate_mdl(t_cmp_fr fr, t_mlx *mlx, int x, int y);
t_cmp_fr		*init_julia();
void			iterate_jul(t_cmp_fr fr, t_mlx *mlx, int x, int y);
t_cmp_fr		*init_burningship();
void			iterate_brn(t_cmp_fr fr, t_mlx *mlx, int x, int y);
int				mouse_move(int x, int y, t_mlx *mlx);
int				handle_mouse(int button, int x, int y, t_mlx *mlx);
int				handle_keys(int key, t_mlx *mlx);
void			translate_x(int x, t_mlx *mlx);
void			translate_y(int y, t_mlx *mlx);
void			zoom(int i, t_mlx *mlx);
int				color_select(int color, int num);
int				scalar(int i, t_cmp_fr *fr, t_color *color);
int				seuss(int i, t_cmp_fr *fr, t_color *color);
int				rainbow(int i, t_cmp_fr *fr, t_color *color);
int				pulse(int i, t_cmp_fr *fr, t_color *color);
int				abstract(int i, t_cmp_fr *fr, t_color *color);
void			shuffle_mode(t_color *color);

#endif
