/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:32:29 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/30 18:26:36 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "fractol.h"

t_mlx	*mlx_free(t_mlx *mlx, char *errmsg);
t_img	*init_img(void *mlx);
t_mlx	*init_mlx(void);

#endif
