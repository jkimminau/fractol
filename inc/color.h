/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:08:33 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/05 21:13:56 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <structs.h>

int				color_select(int color, int num);
int				scalar(int i, t_cmp_fr *fr, t_color *color);
int				seuss(int i, t_cmp_fr *fr, t_color *color);
int				rainbow(int i, t_cmp_fr *fr, t_color *color);
int				pulse(int i, t_cmp_fr *fr, t_color *color);
void			shuffle_mode(t_color *color);

#endif
