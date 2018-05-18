/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:03:04 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/17 18:39:58 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color);
void	draw_line(t_mlx *mlx, t_point p1, t_point p2);
void	center_lines(t_mlx *mlx);
void	draw_map(t_mlx *mlx);

#endif
