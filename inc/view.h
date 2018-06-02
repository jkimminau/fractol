/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:48:01 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/02 15:34:46 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

#include <fractol.h>

void	translate_x(int x, t_mlx *mlx);
void	translate_y(int y, t_mlx *mlx);
void	zoom(int i, t_mlx *mlx);
void	render(t_mlx *mlx);

#endif
