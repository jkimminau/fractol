/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:03:04 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 20:49:17 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define THREADS 500

# include "fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color);
void	*draw_thread(void *arg);
void	render(t_mlx *mlx);

#endif
