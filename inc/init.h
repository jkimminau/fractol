/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:32:29 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 16:50:45 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "fractol.h"

t_mlx		*mlx_free(t_mlx *mlx, char *errmsg);
t_img		*init_img(void *mlx);
t_color		*init_color(void);
t_cmp_fr	*init_cmp_fr(int frac, t_mlx *mlx);
t_mlx		*init_mlx(int frac);

#endif
