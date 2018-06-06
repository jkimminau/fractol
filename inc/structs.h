/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/06 15:47:32 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

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
#endif
