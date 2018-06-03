/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:06:35 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 19:44:54 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "fractol.h"

int		mouse_move(int x, int y, t_mlx *mlx);
int		handle_mouse(int button, int x, int y, t_mlx *mlx);

#endif
